#include "solve.h"

std::vector<int> create_given_list(int num_args, char** argv) {
    std::vector<int> given_list;
    for (int i = 1; i <= num_args; i++) {
        int temp = std::stoi(argv[i]);
        given_list.push_back(temp);
    }
    return given_list;
}

/*
  function called solve_game(input array, index, where_to_move);
  Base case: We're one move away.
    print i?
    make the move to actually get us to the end.


  complete move and document it
  find next move


  Recursive case:
    see if move left or right
    using that solution, execute move
    call function again
*/

void solve_game(const std::vector<int>& in_vec, std::vector<int>& out_vec, int curr_position, bool to_left, int counter) {
    if (counter == 100) {
        return;
    }
    // BASE CASE:
    if (in_vec.size() == 1) {
        out_vec.push_back(curr_position);
        return;
    } else if (in_vec.at(curr_position) + curr_position == in_vec.size() - 1) {
        out_vec.push_back(curr_position);
        out_vec.push_back(in_vec.size()-1);
        return;
    }
    // RECURSIVE CASE:
    if (to_left) { // going left
        out_vec.push_back(curr_position);
        curr_position = curr_position - in_vec.at(curr_position);
        counter++;

    } else { // going right
        out_vec.push_back(curr_position);
        curr_position = curr_position + in_vec.at(curr_position);
        counter++;
    }

    if (in_vec.at(curr_position) == 0 ) {
        std::cout << "There is no solution to the given game." << std::endl;
        exit(0);
    } // WE CANNOT MOVE FROM THIS SPOT. NO POSSIBLE SOLUTION EVER!

    if ((curr_position + in_vec.at(curr_position)) > in_vec.size()) {
        to_left = true; // CANNOT GO RIGHT, MUST GO LEFT
    } else if ((curr_position - in_vec.at(curr_position)) < 0){
        to_left = false; // CANNOT GO LEFT, MUST GO RIGHT
    } else if (((curr_position + in_vec.at(curr_position)) > in_vec.size()) && (curr_position - in_vec.at(curr_position) > in_vec.size())) {
        std::cout << "There is no solution to the given game." << std::endl;
        exit(0); // CANNOT DO EITHER
    } else if (check_for_duplicates(in_vec, curr_position)) {
        to_left = false; // WE DONT WANNA GO LEFT HERE SINCE IT CAN CAUSE A LOOP.
    } else {
        to_left = choose_better_choice(in_vec, curr_position, counter); // EITHER WORKS, FIND BETTER CHOICE
    }

    solve_game(in_vec, out_vec, curr_position, to_left, counter);
}

bool check_for_duplicates(const std::vector<int>& vec,int curr_position) {
        for (int i = 0; i < curr_position; i++) {
            if (vec.at(curr_position) == vec.at(i)) {
                return true;
            }
        }
        return false;
}


// run out the entire recursive process and which ever vec has a shorter size will decide the better move

bool choose_better_choice (const std::vector<int>& in_vec, int curr_position, int counter) {
    std::vector<int> left_path_solution;
    solve_game(in_vec, left_path_solution, curr_position, true/* go left */, counter);
    std::vector<int> right_path_solution;
    solve_game(in_vec, right_path_solution, curr_position, false/* go right */, counter);
    int left_size = left_path_solution.size();
    int right_size = right_path_solution.size();
    return left_size <= right_size;
}

void print_solution(const std::vector<int>& vec) {
    if (vec.size() == 1) {
        int i = 0;
        std::cout << "The solution is: {" << vec.at(i) << "}" << std::endl;
        exit(0);
    } else if (vec.size() >= 1000) {
        std::cout << "There is no solution to the given game." << std::endl;
        exit(0);
    } else {
        std::cout << "The solution is: {";
        for (int i = 0; i < vec.size() - 1; ++i) {
            std::cout << vec.at(i) << ", ";
        }
        int i = vec.size() - 1;
        std::cout << vec.at(i);
        std::cout << "}" << std::endl;
    }
}