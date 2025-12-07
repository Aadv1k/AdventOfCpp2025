#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

size_t get_times_split(vector<string>& field) {
    size_t times_split = 0;

    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[i].length(); ++j) {

            if (field[i][j] == '|') {
                if (field[i+1][j] == '.' && i+1 < field.size()) {
                    field[i+1][j] = '|';
                }

                if (field[i+1][j] == '^'  && i+1 < field.size()) {

                    times_split++;

                    if ((int)(j-1) >= 0) field[i+1][j-1] = '|';
                    if (j+1 < field[i].length()) field[i+1][j+1] = '|';

                }
            }
        }
    }

    return times_split;
}

extern "C" void part_a(std::string input) {
    vector<string> matrix;
    string line;

    istringstream iss(input);
    while (getline(iss, line)) matrix.push_back(line);


    size_t offset = distance(matrix[0].begin(), find(matrix[0].begin(), matrix[0].end(), 'S'));
    matrix[1][offset] = '|';

    cout << "Times the taychon beam was split " << get_times_split(matrix) << endl;
}

size_t simulate_timelines(vector<string>& field, size_t start_row = 0) {
    static unordered_map<string, size_t> memo;
    string key = to_string(start_row) + ":";
    for (const auto& row : field) {
        key += row + ",";
    }
    
    if (memo.count(key)) {
        return memo[key];
    }

    auto m_len = field.size();
    if (!m_len) return 0;
    
    auto r_len = field[0].length();

     auto check_idx_within_bounds = [&](int y, int x) { 
         return x >= 0 && x < (int)r_len && y >= 0 && y < (int)m_len; 
     };

    size_t result = 0;
            

    for (size_t i = start_row; i < m_len; ++i) {
        if (i + 1 == m_len) {
            result = 1;
            memo[key] = result;
            return result;
        }

        for (size_t j = 0; j < r_len; ++j) {
            auto cur = field[i][j];
            if (cur == '|') {
                if (check_idx_within_bounds((int)(i+1), (int)j) && field[i+1][j] != '^') {
                    field[i+1][j] = '|';
                    continue;
                }

                 size_t branch_count = 0;

                // left possible
                if (check_idx_within_bounds((int)(i+1), (int)(j-1))) {

                    auto field_copy = vector<string>(field.begin() + i + 1, field.end());
                    field_copy[0][j-1] = '|';

                    branch_count += simulate_timelines(field_copy);
                } 

                // right possible
                if (check_idx_within_bounds((int)(i+1), (int)(j+1))) {

                    auto field_copy = vector<string>(field.begin() + i + 1, field.end());
                    field_copy[0][j+1] = '|';


                    branch_count += simulate_timelines(field_copy);
                }

                result = branch_count;
                memo[key] = result;
                return result;
            }
        }
    }

    result = 1;
    memo[key] = result;
    return result;
}

extern "C" void part_b(std::string input) {
    vector<string> matrix;
    string line;

    istringstream iss(input);
    while (getline(iss, line)) matrix.push_back(line);


    size_t offset = distance(matrix[0].begin(), find(matrix[0].begin(), matrix[0].end(), 'S'));
    matrix[1][offset] = '|';

    auto result = simulate_timelines(matrix, 0);

    cout << "The total timeline for all possible permutations of the beam " <<  result << endl;
}
