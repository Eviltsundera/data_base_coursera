#pragma once
#include "date.h"
#include "token.h"
#include <memory>

struct Node{
public:
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate (const Date& date, const string& event) override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& cmp, const Date& d) : _date(d), _cmp(cmp) {}
    bool Evaluate (const Date& d, const string& event) override;
private:
    Date _date;
    Comparison _cmp;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& cmp, const string& str)
    :_event(str), _cmp(cmp) {}

    bool Evaluate(const Date &date, const string &event);
private:
    string _event;
    Comparison _cmp;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right)
     :_op(op), _left(left), _right(right) { }

    bool Evaluate(const Date& date, const string& event) override;
private:
    LogicalOperation _op;
    shared_ptr<Node> _left, _right;
};