#include <array>
#include <iostream>
#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>

#include <Components/Appearance.hpp>

/*
A(8) Width: 5 Height: 12
B(8) Width: 5 Height: 12
C(8) Width: 5 Height: 12
D(8) Width: 5 Height: 12
E(8) Width: 5 Height: 12
F(8) Width: 5 Height: 12
G(8) Width: 5 Height: 12
H(8) Width: 5 Height: 12
I(8) Width: 5 Height: 12
J(8) Width: 5 Height: 12
K(8) Width: 5 Height: 12
L(8) Width: 5 Height: 12
M(8) Width: 5 Height: 12
N(8) Width: 5 Height: 12
O(8) Width: 5 Height: 12
P(8) Width: 5 Height: 12
Q(8) Width: 5 Height: 12
R(8) Width: 5 Height: 12
S(8) Width: 5 Height: 12
T(8) Width: 5 Height: 12
U(8) Width: 5 Height: 12
V(8) Width: 5 Height: 12
W(8) Width: 5 Height: 12
X(8) Width: 5 Height: 12
Y(8) Width: 5 Height: 12
Z(8) Width: 5 Height: 12
a(8) Width: 5 Height: 12
b(8) Width: 5 Height: 12
c(8) Width: 5 Height: 12
d(8) Width: 5 Height: 12
e(8) Width: 5 Height: 12
f(8) Width: 5 Height: 12
g(8) Width: 5 Height: 12
h(8) Width: 5 Height: 12
i(8) Width: 5 Height: 12
j(8) Width: 5 Height: 12
k(8) Width: 5 Height: 12
l(8) Width: 5 Height: 12
m(8) Width: 5 Height: 12
n(8) Width: 5 Height: 12
o(8) Width: 5 Height: 12
p(8) Width: 5 Height: 12
q(8) Width: 5 Height: 12
r(8) Width: 5 Height: 12
s(8) Width: 5 Height: 12
t(8) Width: 5 Height: 12
u(8) Width: 5 Height: 12
v(8) Width: 5 Height: 12
w(8) Width: 5 Height: 12
x(8) Width: 5 Height: 12
y(8) Width: 5 Height: 12
z(8) Width: 5 Height: 12
0(8) Width: 5 Height: 12
1(8) Width: 5 Height: 12
2(8) Width: 5 Height: 12
3(8) Width: 5 Height: 12
4(8) Width: 5 Height: 12
5(8) Width: 5 Height: 12
6(8) Width: 5 Height: 12
7(8) Width: 5 Height: 12
8(8) Width: 5 Height: 12
9(8) Width: 5 Height: 12
A(12) Width: 8 Height: 18
B(12) Width: 7 Height: 18
C(12) Width: 7 Height: 18
D(12) Width: 7 Height: 18
E(12) Width: 7 Height: 18
F(12) Width: 7 Height: 18
G(12) Width: 7 Height: 18
H(12) Width: 7 Height: 18
I(12) Width: 7 Height: 18
J(12) Width: 7 Height: 18
K(12) Width: 7 Height: 18
L(12) Width: 7 Height: 18
M(12) Width: 7 Height: 18
N(12) Width: 7 Height: 18
O(12) Width: 7 Height: 18
P(12) Width: 7 Height: 18
Q(12) Width: 7 Height: 18
R(12) Width: 7 Height: 18
S(12) Width: 7 Height: 18
T(12) Width: 7 Height: 18
U(12) Width: 7 Height: 18
V(12) Width: 8 Height: 18
W(12) Width: 8 Height: 18
X(12) Width: 7 Height: 18
Y(12) Width: 8 Height: 18
Z(12) Width: 7 Height: 18
a(12) Width: 7 Height: 18
b(12) Width: 7 Height: 18
c(12) Width: 7 Height: 18
d(12) Width: 7 Height: 18
e(12) Width: 7 Height: 18
f(12) Width: 7 Height: 18
g(12) Width: 7 Height: 18
h(12) Width: 7 Height: 18
i(12) Width: 7 Height: 18
j(12) Width: 7 Height: 18
k(12) Width: 7 Height: 18
l(12) Width: 7 Height: 18
m(12) Width: 7 Height: 18
n(12) Width: 7 Height: 18
o(12) Width: 7 Height: 18
p(12) Width: 7 Height: 18
q(12) Width: 7 Height: 18
r(12) Width: 7 Height: 18
s(12) Width: 7 Height: 18
t(12) Width: 7 Height: 18
u(12) Width: 7 Height: 18
v(12) Width: 7 Height: 18
w(12) Width: 8 Height: 18
x(12) Width: 7 Height: 18
y(12) Width: 7 Height: 18
z(12) Width: 7 Height: 18
0(12) Width: 7 Height: 18
1(12) Width: 7 Height: 18
2(12) Width: 7 Height: 18
3(12) Width: 7 Height: 18
4(12) Width: 7 Height: 18
5(12) Width: 7 Height: 18
6(12) Width: 7 Height: 18
7(12) Width: 7 Height: 18
8(12) Width: 7 Height: 18
9(12) Width: 7 Height: 18
A(24) Width: 15 Height: 36
B(24) Width: 15 Height: 36
C(24) Width: 15 Height: 36
D(24) Width: 15 Height: 36
E(24) Width: 15 Height: 36
F(24) Width: 15 Height: 36
G(24) Width: 15 Height: 36
H(24) Width: 15 Height: 36
I(24) Width: 15 Height: 36
J(24) Width: 15 Height: 36
K(24) Width: 15 Height: 36
L(24) Width: 15 Height: 36
M(24) Width: 15 Height: 36
N(24) Width: 15 Height: 36
O(24) Width: 15 Height: 36
P(24) Width: 15 Height: 36
Q(24) Width: 15 Height: 36
R(24) Width: 15 Height: 36
S(24) Width: 15 Height: 36
T(24) Width: 15 Height: 36
U(24) Width: 15 Height: 36
V(24) Width: 15 Height: 36
W(24) Width: 15 Height: 36
X(24) Width: 15 Height: 36
Y(24) Width: 15 Height: 36
Z(24) Width: 15 Height: 36
a(24) Width: 15 Height: 36
b(24) Width: 15 Height: 36
c(24) Width: 15 Height: 36
d(24) Width: 15 Height: 36
e(24) Width: 15 Height: 36
f(24) Width: 15 Height: 36
g(24) Width: 15 Height: 36
h(24) Width: 15 Height: 36
i(24) Width: 15 Height: 36
j(24) Width: 15 Height: 36
k(24) Width: 15 Height: 36
l(24) Width: 15 Height: 36
m(24) Width: 15 Height: 36
n(24) Width: 15 Height: 36
o(24) Width: 15 Height: 36
p(24) Width: 15 Height: 36
q(24) Width: 15 Height: 36
r(24) Width: 15 Height: 36
s(24) Width: 15 Height: 36
t(24) Width: 15 Height: 36
u(24) Width: 15 Height: 36
v(24) Width: 15 Height: 36
w(24) Width: 15 Height: 36
x(24) Width: 15 Height: 36
y(24) Width: 15 Height: 36
z(24) Width: 15 Height: 36
0(24) Width: 15 Height: 36
1(24) Width: 15 Height: 36
2(24) Width: 15 Height: 36
3(24) Width: 15 Height: 36
4(24) Width: 15 Height: 36
5(24) Width: 15 Height: 36
6(24) Width: 15 Height: 36
7(24) Width: 15 Height: 36
8(24) Width: 15 Height: 36
9(24) Width: 15 Height: 36
A(36) Width: 22 Height: 54
B(36) Width: 22 Height: 54
C(36) Width: 22 Height: 54
D(36) Width: 22 Height: 54
E(36) Width: 22 Height: 54
F(36) Width: 22 Height: 54
G(36) Width: 22 Height: 54
H(36) Width: 22 Height: 54
I(36) Width: 22 Height: 54
J(36) Width: 22 Height: 54
K(36) Width: 22 Height: 54
L(36) Width: 22 Height: 54
M(36) Width: 22 Height: 54
N(36) Width: 22 Height: 54
O(36) Width: 22 Height: 54
P(36) Width: 22 Height: 54
Q(36) Width: 22 Height: 54
R(36) Width: 22 Height: 54
S(36) Width: 22 Height: 54
T(36) Width: 22 Height: 54
U(36) Width: 22 Height: 54
V(36) Width: 22 Height: 54
W(36) Width: 22 Height: 54
X(36) Width: 22 Height: 54
Y(36) Width: 22 Height: 54
Z(36) Width: 22 Height: 54
a(36) Width: 22 Height: 54
b(36) Width: 22 Height: 54
c(36) Width: 22 Height: 54
d(36) Width: 22 Height: 54
e(36) Width: 22 Height: 54
f(36) Width: 22 Height: 54
g(36) Width: 22 Height: 54
h(36) Width: 22 Height: 54
i(36) Width: 22 Height: 54
j(36) Width: 22 Height: 54
k(36) Width: 22 Height: 54
l(36) Width: 22 Height: 54
m(36) Width: 22 Height: 54
n(36) Width: 22 Height: 54
o(36) Width: 22 Height: 54
p(36) Width: 22 Height: 54
q(36) Width: 22 Height: 54
r(36) Width: 22 Height: 54
s(36) Width: 22 Height: 54
t(36) Width: 22 Height: 54
u(36) Width: 22 Height: 54
v(36) Width: 22 Height: 54
w(36) Width: 22 Height: 54
x(36) Width: 22 Height: 54
y(36) Width: 22 Height: 54
z(36) Width: 22 Height: 54
0(36) Width: 22 Height: 54
1(36) Width: 22 Height: 54
2(36) Width: 22 Height: 54
3(36) Width: 22 Height: 54
4(36) Width: 22 Height: 54
5(36) Width: 22 Height: 54
6(36) Width: 22 Height: 54
7(36) Width: 22 Height: 54
8(36) Width: 22 Height: 54
9(36) Width: 22 Height: 54
A(48) Width: 29 Height: 72
B(48) Width: 29 Height: 72
C(48) Width: 29 Height: 72
D(48) Width: 29 Height: 72
E(48) Width: 29 Height: 72
F(48) Width: 29 Height: 72
G(48) Width: 29 Height: 72
H(48) Width: 29 Height: 72
I(48) Width: 29 Height: 72
J(48) Width: 29 Height: 72
K(48) Width: 29 Height: 72
L(48) Width: 29 Height: 72
M(48) Width: 29 Height: 72
N(48) Width: 29 Height: 72
O(48) Width: 29 Height: 72
P(48) Width: 29 Height: 72
Q(48) Width: 29 Height: 72
R(48) Width: 29 Height: 72
S(48) Width: 29 Height: 72
T(48) Width: 29 Height: 72
U(48) Width: 29 Height: 72
V(48) Width: 29 Height: 72
W(48) Width: 29 Height: 72
X(48) Width: 29 Height: 72
Y(48) Width: 29 Height: 72
Z(48) Width: 29 Height: 72
a(48) Width: 29 Height: 72
b(48) Width: 29 Height: 72
c(48) Width: 29 Height: 72
d(48) Width: 29 Height: 72
e(48) Width: 29 Height: 72
f(48) Width: 29 Height: 72
g(48) Width: 29 Height: 72
h(48) Width: 29 Height: 72
i(48) Width: 29 Height: 72
j(48) Width: 29 Height: 72
k(48) Width: 29 Height: 72
l(48) Width: 29 Height: 72
m(48) Width: 29 Height: 72
n(48) Width: 29 Height: 72
o(48) Width: 29 Height: 72
p(48) Width: 29 Height: 72
q(48) Width: 29 Height: 72
r(48) Width: 29 Height: 72
s(48) Width: 29 Height: 72
t(48) Width: 29 Height: 72
u(48) Width: 29 Height: 72
v(48) Width: 29 Height: 72
w(48) Width: 29 Height: 72
x(48) Width: 29 Height: 72
y(48) Width: 29 Height: 72
z(48) Width: 29 Height: 72
0(48) Width: 29 Height: 72
1(48) Width: 29 Height: 72
2(48) Width: 29 Height: 72
3(48) Width: 29 Height: 72
4(48) Width: 29 Height: 72
5(48) Width: 29 Height: 72
6(48) Width: 29 Height: 72
7(48) Width: 29 Height: 72
8(48) Width: 29 Height: 72
9(48) Width: 29 Height: 72
 */

constexpr size_t ALPHABET_SIZE = 26 + 26 + 10;
static const std::array<char, ALPHABET_SIZE> ALPHABET() {
  static const std::array<char, ALPHABET_SIZE> characters = [] {
    std::array<char, ALPHABET_SIZE> chars{};

    size_t index = 0;
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

int main() {
  std::cout << "Print Font Sizes\n";
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Initialize SDL2_ttf
  if (TTF_Init() != 0) {
    std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("SDL with EnTT Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (!window) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  for (Components::FontSize fontSize : Components::ALL_FONT_SIZES) {
    // Load a font
    TTF_Font *font = TTF_OpenFont("resources/SpaceMono.ttf", static_cast<int>(fontSize)); // Adjust font path and size as needed
    if (!font) {
      std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      TTF_Quit();
      SDL_Quit();
      return 1;
    }
    // TODO: iterate through all the letters
    for (auto letter : ALPHABET()) {
      int textWidth = 0;
      int textHeight = 0;
      if (TTF_SizeText(font, &letter, &textWidth, &textHeight) != 0) {
        std::cerr << "TTF_SizeText Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
      }
      std::cout << letter << "(" << static_cast<int>(fontSize) << ")" << " Width: " << textWidth << " Height: " << textHeight << std::endl;
    }

    TTF_CloseFont(font);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
  return 0;
}