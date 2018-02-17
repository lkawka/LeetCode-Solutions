/*
 Problem:
 According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 
 Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 
 Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 Any live cell with two or three live neighbors lives on to the next generation.
 Any live cell with more than three live neighbors dies, as if by over-population..
 Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 Write a function to compute the next state (after one update) of the board given its current state.
 
 Follow up:
 Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
 In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int N = board.size(), M = (N > 0 ? board[0].size() : 0);
        vector<pair<int,int>> positions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> solution(N, vector<int>(M));
            
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                int aliveCellsAround = 0;
                for(int k = 0; k < positions.size(); k++) {
                    int iPos = i+positions[k].first, jPos = j+positions[k].second;
                    if(iPos >= 0 && iPos < N && jPos >=0 && jPos < M) {
                        aliveCellsAround += board[iPos][jPos];
                    }
                }
                if(board[i][j]) {
                    if(aliveCellsAround == 2 || aliveCellsAround == 3)
                        solution[i][j] = 1;
                    else
                        solution[i][j] = 0;
                } else {
                    if(aliveCellsAround == 3) 
                        solution[i][j] = 1;
                    else
                        solution[i][j] = 0;
                }
            }
        }
        
        board = solution;
    }
};
