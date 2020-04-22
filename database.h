#pragma once

#include <map>
#include <vector>
#include <set>
#include <functional>
#include "date.h"

class Database{
public:
    void Print(std::ostream& out) const;
    void Add(const Date& d, const std::string& event);
    int RemoveIf(std::function<bool (const Date &, const std::string &)> pred);
    std::string Last(const Date& d) const;
    std::vector<std::string> FindIf(std::function<bool (const Date &, const std::string &)> pred) const;
private:
    std::map<Date, std::vector<std::string>> data_v;
    std::map<Date, std::set<std::string>> data_s;
};