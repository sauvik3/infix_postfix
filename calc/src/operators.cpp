// Copyright 2025 Sauvik Roy

#include "operators.hpp"

namespace calc {
template <> double add(double a, double b) { return a + b; }

template <> double subtract(double a, double b) { return a - b; }

template <> double multiply(double a, double b) { return a * b; }

template <> double divide(double a, double b) { return a / b; }

template <> double inverse(double a) { return 1.0 / a; }

}   // namespace calc
