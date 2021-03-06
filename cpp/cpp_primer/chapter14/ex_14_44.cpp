//
// Created by kaiser on 18-12-24.
//

#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string,
                     std::function<std::int32_t(std::int32_t, std::int32_t)>>
      binops{
          {"+", std::plus<>{}},
          {"-", std::minus<>{}},
          {"*", std::multiplies<>{}},
          {"/", std::divides<>{}},
      };

  std::string op;
  std::int32_t lhs, rhs;

  // 注意要输入空格
  std::cin >> lhs >> op >> rhs;
  std::cout << binops[op](lhs, rhs) << '\n';
}
