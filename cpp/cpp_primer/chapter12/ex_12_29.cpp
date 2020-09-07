//
// Created by kaiser on 18-12-19.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "ex_12_27.h"

void run_queries(std::ifstream& input)
{
    TextQuery tq{input};
    do {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s)) << '\n';
    } while (true);
}

int main()
{
    std::ifstream ifs{"story"};
    if (!ifs) {
        std::cerr << "can not open file\n";
        return EXIT_FAILURE;
    }

    run_queries(ifs);
}
