#include "date.h"

Date::Date(const std::string& str) {
    std::stringstream input(str);
    input >> _year;
    input.ignore(1);
    input >> _month;
    input.ignore(1);
    input >> _day;
}

Date::Date(int year, int month, int day)
        :_year(year), _month(month), _day(day) {}

Date ParseDate(std::istream& input) {
    std::string tmp;
    input >> tmp;
    return Date(tmp);
}

bool Date::operator<(const Date& obj) const {
    auto x = std::make_tuple(_year, _month, _day);
    auto y = std::make_tuple(obj._year, obj._month, obj._day);
    return x < y;
}

std::ostream& operator<<(std::ostream& out, const Date &d) {
    out << std::setfill('0') << std::setw(4) << d._year << "-"
            << std::setfill('0') << std::setw(2) << d._month << "-"
                << std::setfill('0') << std::setw(2) << d._day;
    return out;
}

bool Date::operator==(const Date& d) const{
    return (_year == d._year) && (_month == d._month) && (_day == d._day);
}

bool Date::operator!=(const Date& d) const {
    return !operator==(d);
}

bool Date::operator<=(const Date& d) const {
    return ((operator==(d)) or (operator<(d)));
}

bool Date::operator>=(const Date& d) const {
    return operator>(d) or operator==(d);
}

bool Date::operator>(const Date& d) const {
    return !operator<=(d);
}


