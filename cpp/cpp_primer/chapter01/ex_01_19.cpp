#include <algorithm>
#include <cstdint>
#include <iostream>

int main() {
  std::int32_t v1;
  std::int32_t v2;
  std::cin >> v1 >> v2;

  if (v1 > v2) {
    std::swap(v1, v2);
  }

  while (v1 <= v2) {
    std::cout << v1 << ' ';
    ++v1;
  }
  std::cout << '\n';
}
