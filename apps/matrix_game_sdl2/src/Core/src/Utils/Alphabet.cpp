#include <Utils/Alphabet.hpp>

#include <array>
#include <cstdlib>
namespace Utils {

const std::array<char, Utils::ALPHABET_SIZE> ALPHABET() {
  static const std::array<char, Utils::ALPHABET_SIZE> characters = [] {
    std::array<char, Utils::ALPHABET_SIZE> chars{};

    int index = 0;
    // Add uppercase letters
    for (char c = 'A'; c <= 'Z'; ++c) {
      chars[index++] = c;
    }

    // Add lowercase letters
    for (char c = 'a'; c <= 'z'; ++c) {
      chars[index++] = c;
    }

    // Add digits
    for (char c = '0'; c <= '9'; ++c) {
      chars[index++] = c;
    }

    return chars;
  }();
  return characters;
}
const char RANDOM_LETTER() {
  int letterIndex = rand() % ALPHABET_SIZE;
  return ALPHABET().at(letterIndex);
}
} // namespace Utils
