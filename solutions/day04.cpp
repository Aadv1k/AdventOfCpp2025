#include <iostream>
#include <vector>
#include <sstream>

#define NUM_DIRECTIONS 8

static const int kDirections[][2] = { 
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},        {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

extern "C" void part_a(std::string input) {
    std::istringstream iss(input);
    std::string line;

    std::vector<std::string> matrix;
    while (std::getline(iss, line, '\n')) matrix.push_back(line);


    // We know line length is uniform
    int line_length = matrix[0].length(),
        matrix_len = matrix.size();

    auto total_accessible_rolls = 0;

    for (int i = 0; i <= matrix_len; ++i) {
        for (int j = 0; j <= line_length; ++j) {
            if (matrix[i][j] != '@') continue;
            //std::cout << i << ", " << j << "\n";

            auto has_paper_roll = 0;
            for (int k = 0; k < NUM_DIRECTIONS; ++k) {
                int x = i + kDirections[k][0];
                int y = j + kDirections[k][1];

                if ((x >= 0 && x < line_length) && (y >= 0 && y < line_length) && matrix[x][y] == '@')  has_paper_roll++;
            }


            if (has_paper_roll < 4) total_accessible_rolls++;
        }

    }

    std::cout << "The total number of accessible paper rolls is " << total_accessible_rolls << "\n";
}

extern "C" void part_b(std::string input) {
    std::istringstream iss(input);
    std::string line;

    std::vector<std::string> matrix;
    while (std::getline(iss, line, '\n')) matrix.push_back(line);

    // We know line length is uniform
    int line_length = matrix[0].length(),
        matrix_len = matrix.size();

    auto total_removed_rolls  = 0;
    std::vector<std::string> current_state = matrix;

    for (;;) {
        auto removable_rolls = 0;
        std::vector<std::string> next_state = current_state;

        for (int i = 0; i <= matrix_len; ++i) {
            for (int j = 0; j <= line_length; ++j) {
                if (current_state[i][j] != '@') continue;

                auto has_paper_roll = 0;
                for (int k = 0; k < NUM_DIRECTIONS; ++k) {
                    int x = i + kDirections[k][0];
                    int y = j + kDirections[k][1];

                    if ((x >= 0 && x < line_length) && (y >= 0 && y < line_length) && current_state[x][y] == '@')  has_paper_roll++;
                }


                if (has_paper_roll < 4) {
                    removable_rolls++;
                    next_state[i][j] = '.';
                };
            }
        }


        current_state = next_state;
        total_removed_rolls += removable_rolls;
    }


    std::cout << "Total numbers of rolls removed were " << total_removed_rolls << "\n";
}
