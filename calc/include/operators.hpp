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

template <typename T> T negative(T a);
}   // namespace calc
