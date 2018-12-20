//
// Created by kaiser on 18-12-5.
//

#include <vector>
#include <cstdint>
#include <iostream>

std::vector<std::int32_t>::iterator
Find(std::vector<std::int32_t>::iterator begin,
     std::vector<std::int32_t>::iterator end, std::int32_t value) {
  for (; begin != end; ++begin) {
    if (*begin == value)
      return begin;
  }
  return end;
}

int main() {
  std::vector<std::int32_t> vi{1, 2, 3};
  if (Find(std::begin(vi), std::end(vi), 2) != std::end(vi)) {
    std::cout << "found\n";
  } else {
    std::cout << "not found\n";
  }
}