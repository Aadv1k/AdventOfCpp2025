#include <sstream>
#include <iostream>
#include <vector>
#include <set>

extern "C" void part_a(std::string input) {
    std::istringstream iss(input);
    std::string line;

    auto next_chunk = false;

    std::vector<std::array<size_t, 2>> pairs;

    auto fresh_count = 0;
    std::set<size_t> fresh_ids;

    while (std::getline(iss, line, '\n')) {
        if (line == "") {
            next_chunk = true;
            continue;
        }

        if (!next_chunk) {
            size_t lhs, rhs; 
            sscanf(line.c_str(), "%zu-%zu", &lhs, &rhs);
            pairs.push_back({ lhs, rhs });
            continue;
        }


        size_t current_digit = std::stoull(line);
        for (const auto& pair: pairs) {
            if (current_digit >= pair[0] && current_digit <= pair[1]) {
                if (fresh_ids.find(current_digit) != fresh_ids.end()) continue;

                fresh_count++;
                fresh_ids.insert(current_digit);

            }
        }
    }

    std::cout << "Total fresh ingredient IDs from the list: " << fresh_count << std::endl;
}


int count_elements_in_range(int a, int b) {
    return (b > a ? b - a : a - b) + 1;
}


/*
extern "C" void part_b(std::string input) {
    std::istringstream iss(input);
    std::string line;

    std::vector<std::array<int, 2>> pairs;

    size_t total_valid_elements = 0;

    while (std::getline(iss, line, '\n')) {
        if (line == "") break;

        bool skip = false;

        int lhs, rhs; 
        sscanf(line.c_str(), "%d-%d", &lhs, &rhs);
         
        for (const auto& pair : pairs) {
            if ((pair[0] < lhs) || (pair[1] > rhs)) {
               auto a = abs(pair[0] - lhs),
                    b = abs(pair[1] - rhs);

                total_valid_elements += count_elements_in_range(a, b);

                skip = true;
                break;
            }
        }

        if (skip) continue;

        //std::cout << count_elements_in_range(lhs, rhs) << "\n";

        total_valid_elements += count_elements_in_range(lhs, rhs);
        pairs.push_back({ lhs, rhs });

    }

    std::cout << "Total fresh ingredient IDs: " << total_valid_elements << std::endl;
}*/

/*
 
      |------------------------|
                        |--------|




bool check_if_has_overlap(std::array<int, 2>& a, std::array<int, 2>& b) {
    if (b[1] > a[0] && b[0] < a[1]) || ()
}

extern "C" void part_b(std::string input) {
    std::istringstream iss(input);
    std::string line;

    std::vector<std::array<int, 2>> pairs;

    size_t total_valid_elements = 0;

    while (std::getline(iss, line, '\n')) {
        if (line == "") break;

        int lhs, rhs; 
        sscanf(line.c_str(), "%d-%d", &lhs, &rhs);
        pairs.push_back({ lhs, rhs });

    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {


        }
    }

    std::cout << "Total fresh ingredient IDs: " << total_valid_elements << std::endl;
}
*/
