//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <string>

int main() {
  std::string s("hello world");
  for (auto&& element : s) {
    element = 'X';
  }
  std::cout << s << '\n';
}
