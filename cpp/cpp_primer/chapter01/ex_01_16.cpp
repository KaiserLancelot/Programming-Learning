#include <cstdint>
#include <iostream>

int main() {
  std::int32_t sum{};
  std::int32_t val;

  while (std::cin >> val) {
    sum += val;
  }

  std::cout << sum << '\n';
}
