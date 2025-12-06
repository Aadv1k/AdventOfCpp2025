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
