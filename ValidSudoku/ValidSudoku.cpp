#include <iostream>
#include <unordered_map>

class Solution 
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            std::unordered_map<char, int> row;
            std::unordered_map<char, int> column;
            for (int j = 0; j < 9; j++)
            {
                column[board[j][i]]++;
                if (board[j][i] != '.' && column[board[j][i]] > 1)
                    return false;

                row[board[i][j]]++;
                if (board[i][j] != '.' && row[board[i][j]] > 1)
                    return false;
            }
        }

        for (int k = 0; k < 3; k++)
        {
            for (int z = 0; z < 3; z++)
            {
                std::unordered_map<char, int> sub_box;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        char val = board[i + 3 * k][j + z * 3];

                        sub_box[val]++;
                        if (val != '.' && sub_box[val] > 1)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};


int main()
{
    Solution solution;

    std::vector<std::vector<char>> board =
        {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
         {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
         {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
         {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << solution.isValidSudoku(board) << std::endl;

    std::vector<std::vector<char>> board2 =
       {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '1', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << solution.isValidSudoku(board2) << std::endl;
}
