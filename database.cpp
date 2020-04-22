#pragma once

#include "database.h"

void Database::Print(std::ostream& out) const {
    for(const auto& item : data_v) {
        for (const auto& event : item.second) {
            out << item.first << " " << event << std::endl;
        }
    }
}

void Database::Add(const Date& d, const std::string& event) {
    if(data_s[d].find(event) == data_s[d].end()) {
        data_v[d].push_back(event);
        data_s[d].insert(event);
    }
}

int Database::RemoveIf(std::function<bool (const Date &, const std::string &)> pred) {
    int counter = 0;
    std::vector<Date> remove;
    for(auto& [date, events] : data_v) {
        /*for(const auto& event : events) {
            if (pred(date, event)) {
                counter++;
                std::cerr << event << std::endl;
                data_s[date].erase(event);

                if (data_s[date].empty()) {
                    remove.push_back(date);
                }
                std::stable_partition(events.begin(), events.end(),
                        [event](const std::string& str) {
                    return str != event;
                });

            }
        }*/
        Date d = date;
        auto new_end = std::stable_partition(events.begin(), events.end(), [d, pred] (std::string e) {
            return !pred(d, e);
        });
        counter += events.end() - new_end;
        for(auto it = new_end; it < events.end(); it++) {
            data_s[date].erase(*it);
        }
        events.resize(new_end - events.begin());
        if(events.empty()) {
            remove.push_back(date);
        }
    }

    for(auto date : remove) {
        data_v.erase(date);
        data_s.erase(date);
    }
    return counter;
}

std::string Database::Last(const Date& d) const {
    // auto it = std::lower_bound(data_v.begin(), data_v.end(), d);
    if (data_v.empty()) {
        throw std::invalid_argument("error");
    }
    auto it = data_v.lower_bound(d);
    if(it->first == d) {
        std::stringstream out;
        out << it->first << " " << it->second[it->second.size() - 1];
        return out.str();
    }

    if (it == data_v.begin()) {
        throw std::invalid_argument("error");
    }

    it--;
    std::stringstream out;
    out << it->first << " " << it->second[it->second.size() - 1];
    return out.str();
}

std::vector<std::string> Database::FindIf(std::function<bool (const Date &, const std::string &)> pred) const {
    std::vector<std::string> ans;
    for(const auto& [date, events] : data_v) {
        for (const auto& event : events) {
            if(pred(date, event)) {
                std::stringstream out;
                out << date << " " << event;
                ans.push_back(out.str());
            }
        }
    }
    return ans;
}



