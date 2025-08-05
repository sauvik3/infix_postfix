// Copyright 2025 Sauvik Roy

#include "operators.hpp"

namespace calc {
template <typename T> T add(T a, T b) { return a + b; }

template <typename T> T subtract(T a, T b) { return a - b; }

template <typename T> T multiply(T a, T b) { return a * b; }

template <typename T> T divide(T a, T b) { return a / b; }

template <typename T> T inverse(T a) { return 1.0 / a; }
}   // namespace calc
