#pragma once

#include <string>
#include <iostream>
#include <tuple>
#include <iomanip>

class Date {
public:
    Date(const std::string& str);
    Date(int year, int month, int day);
    bool operator<(const Date& obj)const;
    friend std::ostream& operator<<(std::ostream& out, const Date& d);
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator>(const Date& d) const;
private:
    int _year{}, _month{}, _day{};
};

Date ParseDate(std::istream& input);
