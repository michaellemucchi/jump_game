#include "solve.h"

int main(int argc, char** argv) {
    int num_args = argc - 1;
    std::vector<int> given_list = create_given_list(num_args, argv);
    if (num_args == 0 ) {
        std::cout << "There is no solution to the given game." << std::endl;
        exit(0);
    }
    int curr_position = 0;
    bool go_left = false;
    std::vector<int> out_vec;
    int counter = 0;
    solve_game(given_list, out_vec, curr_position, go_left, counter);
    print_solution(out_vec);
    return 0;
}
