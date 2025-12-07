#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cassert>

using namespace std;

extern "C" void part_a(std::string input) {
    istringstream iss(input);
    string line;

    vector<vector<size_t>> matrix;
    vector<char> ops;

    size_t check_last_len = 0;
    

    while (getline(iss, line)) {
        bool is_op_line = false;

        vector<size_t> row;

        istringstream line_stream(line);
        string word;

        while (getline(line_stream, word, ' ')) {
            if (word == "*" || word == "+") {
                if (!is_op_line) is_op_line = true;
                ops.push_back(word[0]);
            } else {
                if (all_of(word.begin(), word.end(), [](unsigned char c) { return isspace(c); })) 
                    continue;

                size_t digit = stoull(word);
                row.push_back(digit);
            }
        }

        if (is_op_line) break;

        matrix.push_back(row);

        if (check_last_len != 0 && row.size() != check_last_len) {
            cout << "Expected rows to be equal, instead last row was " << check_last_len << " and current is "  << row.size() << endl;
            assert(false);
        }

        if (check_last_len == 0) check_last_len = row.size();
    }

    auto m_len = matrix.size();
    size_t grand_total = 0;
;
    for (size_t i = 0; i < matrix[0].size(); ++i) {
        size_t total = 0;
        for (size_t j = 0; j < m_len; ++j) {
            if (ops[i] == '*') {
                if (total == 0) total = 1;
                total *= matrix[j][i];
            } else if ( ops[i] == '+' ) {
                total += matrix[j][i];
            }
        }

        grand_total += total;
    }


    cout << "The grand total of all the answers in the worksheet is " << grand_total << endl;
}

size_t perform_op(vector<size_t> nums, char op) {
    size_t result = 0;
    for (const auto& num : nums) {
        if (num == 0) continue;

        if (op == '*') {
            if (result == 0) result = 1;
            result *= num;
            continue;
        } 

        result += num;
    }

    return result;
}


extern "C" void part_b(std::string input) {
    istringstream iss(input);
    string line;

    vector<string> matrix;

    while (getline(iss, line)) matrix.push_back(line);

    auto m_len = matrix.size(),
         r_len = matrix[0].length();

    vector<size_t> results,
                    stack;

    for (int i = r_len; i >= 0; --i) {
        string digit;

        for (size_t j = 0; j < m_len; ++j) {

            if (matrix[j][i] == '*' || matrix[j][i] == '+') {
                try {
                    stack.push_back(stoull(digit));
                } catch (std::invalid_argument) {
                    continue;
                }

                auto result = perform_op(stack, matrix[j][i]);

                results.push_back(result);

                stack.clear();
                digit = "";

                i-=1;
                break;
            }

            digit += matrix[j][i];
        }

        try {
            stack.push_back(stoull(digit));
        } catch (std::invalid_argument) {
            continue;
        }
    }

    size_t grand_total = 0;
    for (const auto& result : results) {
        grand_total += result;
    }


    cout << "The grand total of all the individual answers in the worksheet is " << grand_total << endl;

}
