#include <iostream>
#include <sstream>
#include <functional>

#define WORD_LEN 256

bool is_repeating_string(std::string input, const std::function <bool(int)>& fn_match_condition) {
    std::string buffer;
    auto len = input.length();

    for (size_t i = 0; i < len; ++i) {
        auto lookahead = buffer.length();

        if (!lookahead) {
            buffer += input[i];
            continue;
        }

        lookahead++;

        size_t cnt = 0;

        for (size_t j = 0; j < lookahead && i+j < len; ++j) {
            if (buffer[j] != input[i+j]) break;
            cnt+=1;
        }

        if (cnt == lookahead-1) {
            size_t full_match = 0,
                   seq_len = lookahead-1;
            
            // This ensures we also check the "left over" string when parts are matched
            auto parts = std::ceil(static_cast<double>(len) / seq_len);

            for (size_t k = 0; k < parts; ++k) {
                if (input.substr(k*(seq_len), seq_len) == buffer) full_match++;
            }

            if (full_match == parts && fn_match_condition(full_match)) 
                return true;
        };

        buffer += input[i];
    }

    return false;
}

extern "C" void part_a(std::string input) {
    std::istringstream iss(input);

    std::string chunk;
    char lhs[WORD_LEN];
    char rhs[WORD_LEN];

    size_t sum_invalid_ids = 0;

    while (std::getline(iss, chunk, ',')) {
        sscanf(chunk.c_str(), "%[^-]-%s", &lhs[0], &rhs[0]);

        size_t lhs_num = std::stoull(lhs);
        size_t rhs_num = std::stoull(rhs);

        for (size_t i = lhs_num; i <= rhs_num; ++i) {
            auto num_as_str = std::to_string(i);
            if (is_repeating_string(num_as_str, [](int m) { return m <= 2; })) {
                sum_invalid_ids += i;
            };
        }
    }

    std::cout << "Sum of all invalid IDs: " << sum_invalid_ids << std::endl;
}

extern "C" void part_b(std::string input) {
    std::istringstream iss(input);

    std::string chunk;
    char lhs[WORD_LEN];
    char rhs[WORD_LEN];

    size_t sum_invalid_ids = 0;

    while (std::getline(iss, chunk, ',')) {
        sscanf(chunk.c_str(), "%[^-]-%s", &lhs[0], &rhs[0]);

        size_t lhs_num = std::stoull(lhs);
        size_t rhs_num = std::stoull(rhs);

        for (size_t i = lhs_num; i <= rhs_num; ++i) {
            auto num_as_str = std::to_string(i);
            if (is_repeating_string(num_as_str, [](int m) { return m >= 2; })) {
                sum_invalid_ids += i;
            };
        }
    }

    std::cout << "Sum of all invalid IDs w/ seq gt_or_eq 2: " << sum_invalid_ids << std::endl;
}
