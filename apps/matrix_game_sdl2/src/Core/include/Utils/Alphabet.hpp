#pragma once
#include <array>

namespace Utils {
constexpr int ALPHABET_SIZE = 26 + 26 + 10;
const std::array<char, ALPHABET_SIZE> ALPHABET();
const char RANDOM_LETTER();
} // namespace Utils
