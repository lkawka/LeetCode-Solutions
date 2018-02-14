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