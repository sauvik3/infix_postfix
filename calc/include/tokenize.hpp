// Copyright 2025 Sauvik Roy
#pragma once

#include <string>
#include <utility>
#include <vector>

#include "tokens.hpp"

namespace calc {
using Token = std::pair<std::string, enum Operator>;

std::vector<Token> tokenize(const std::string &expInput);
}
