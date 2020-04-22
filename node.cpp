#pragma once

#include "node.h"

bool EmptyNode::Evaluate (const Date& date, const string& event) {
    return true;
}

bool DateComparisonNode::Evaluate (const Date& d, const string& event) {
    if (_cmp == Comparison::Less) {
        return _date > d;
    }

    if (_cmp == Comparison::LessOrEqual) {
        return d <= _date;
    }

    if (_cmp == Comparison::Greater) {
        return  _date < d;
    }

    if (_cmp == Comparison::GreaterOrEqual) {
        return _date <= d;
    }

    if (_cmp == Comparison::Equal) {
        return _date == d;
    }

    if (_cmp == Comparison::NotEqual) {
        return _date != d;
    }
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) {
    if(_cmp == Comparison::Equal){
        return  event == _event;
    }
    if(_cmp == Comparison::NotEqual){
        return event != _event;
    }
    if (_cmp == Comparison::Less) {
        return _event > event;
    }

    if (_cmp == Comparison::LessOrEqual) {
        return event <= _event;
    }

    if (_cmp == Comparison::Greater) {
        return  _event < event;
    }

    if (_cmp == Comparison::GreaterOrEqual) {
        return _event <= event;
    }
    return 0;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {
    if (_op == LogicalOperation::And) {
    return _left->Evaluate(date, event) && _right->Evaluate(date, event);
    }
    else if (_op == LogicalOperation::Or) {
    return _left->Evaluate(date, event) || _right->Evaluate(date, event);
    }
    return 0;
}
