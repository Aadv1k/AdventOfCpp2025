#include <sstream>
#include <iostream>
#include <print>

size_t find_max_idx_in_string(std::string input, size_t exclude_idx) { 
    int max_idx = -1;
    for (size_t i = 0; i <= input.length(); ++i) {
        if (i == exclude_idx) continue;

        if (max_idx == -1 || input[max_idx] < input[i]) {
            max_idx = i;
        }
    }

    return max_idx;
}

extern "C" void part_a(std::string input) {
    std::istringstream iss(input);
    std::string line;


    size_t total_joltage = 0;
    while (std::getline(iss, line, '\n')) {
        auto first_elem_idx = find_max_idx_in_string(line, -1);

        auto rhs = line.substr(first_elem_idx+1, line.length()),
             lhs = line.substr(0, first_elem_idx);

        size_t second_elem_idx;
        std::string digit;

        if (rhs.length() == 0) {
            second_elem_idx = find_max_idx_in_string(lhs, -1);
            // order -> second_elem, first_elem

            digit += line[second_elem_idx];
            digit += line[first_elem_idx];
        }  else {
            second_elem_idx = find_max_idx_in_string(rhs, -1)+first_elem_idx+1;
            // order -> first, second_elem

            digit += line[first_elem_idx];
            digit += line[second_elem_idx];
        }

        total_joltage += std::stoull(digit);
    }

    std::cout << "The total joltage is " << total_joltage << "\n";
}


size_t find_max_idx_such_that_rhs_has_atleast_n_elements(std::string input, size_t n) { 
    std::vector<std::array<size_t, 2>> candidates;

    int max_idx = -1;
    for (size_t i = 0; i <= input.length(); ++i) {
        if (max_idx == -1 || (input[max_idx] < input[i] && (input.length() - i) >= n)) {
            //candidates.push_back({ i, input[i] })
            max_idx = i;
        }
    }



    /*
    std::cout << candidates.length() << std::endl;
    std::array<size_t> ans = nullptr;
    for (auto i = candidates.begin(); i != candidates.end(); ++i) {
        i[0]

    }*/

    return max_idx;
}



extern "C" void part_b(std::string input) {
    std::istringstream iss(input);
    std::string line;

    size_t total_big_joltage = 0; 
    while (std::getline(iss, line, '\n')) {
        auto rhs = line;

        auto offset = static_cast<size_t>(0),
            len = line.length();


        std::string digit; 
        for (int i = 12; i > 0; --i) {

            size_t output_idx = find_max_idx_such_that_rhs_has_atleast_n_elements(rhs, i) + offset;

            digit += line[output_idx];
            //std::cout << line[output_idx];

            rhs = line.substr(output_idx + 1, len);
            offset = output_idx + 1;
        }

        total_big_joltage += std::stoull(digit);

        //std::cout << std::endl;
    }

    std::cout << "The total BIG joltage is " << total_big_joltage << "\n";
}
