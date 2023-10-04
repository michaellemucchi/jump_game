#ifndef JUMPGAME_SOLVE_H
#define JUMPGAME_SOLVE_H

    #include <iostream>
    #include <vector>

    void solve_game(const std::vector<int>& in_vec, std::vector<int>& out_vec, int curr_position, bool to_left, int counter);
    std::vector<int> create_given_list(int num_args, char** argv);
    bool choose_better_choice (const std::vector<int>& in_vec, int curr_position, int counter);
    void print_solution(const std::vector<int>& vec);
    bool check_for_duplicates(const std::vector<int>& vec,int curr_position);

#endif //JUMPGAME_SOLVE_H
