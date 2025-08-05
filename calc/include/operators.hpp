// Copyright 2025 Sauvik Roy
#pragma once

#include <functional>
#include <map>
#include <utility>

#include "tokens.hpp"

namespace calc {
template <typename T> T add(T a, T b);

template <typename T> T subtract(T a, T b);

template <typename T> T multiply(T a, T b);

template <typename T> T divide(T a, T b);

template <typename T> T inverse(T a);

template <typename T, class... Args>
static const std::map<enum Operator, std::function<T(Args...)>>
    operatorImpl = {
        std::make_pair(Operator::ADD, add),
        std::make_pair(Operator::SUBTRACT, subtract),
        std::make_pair(Operator::MULTIPLY, multiply),
        std::make_pair(Operator::DIVIDE, divide),
        std::make_pair(Operator::INVERSE, inverse),
};
}   // namespace calc
