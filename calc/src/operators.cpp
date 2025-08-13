// Copyright 2025 Sauvik Roy

#include <cmath>

#include "operators.hpp"

namespace calc {
template <> double add(double a, double b) { return a + b; }

template <> double subtract(double a, double b) { return a - b; }

template <> double multiply(double a, double b) { return a * b; }

template <> double divide(double a, double b) { return a / b; }

template <> double inverse(double a) { return 1.0 / a; }

template <> double negative(double a) { return -1.0 * a; }

template <> double power(double a, double b) { return std::pow(a, b); }

template <> double sqrt(double a) { return std::sqrt(a); }

template <> double abs(double a) { return std::abs(a); }

template <> double sin(double a) { return std::sin(a); }

template <> double cos(double a) { return std::cos(a); }

template <> double tan(double a) { return std::tan(a); }

template <> double log(double a) { return std::log10(a); }

template <> double ln(double a) { return std::log(a); }

}   // namespace calc
