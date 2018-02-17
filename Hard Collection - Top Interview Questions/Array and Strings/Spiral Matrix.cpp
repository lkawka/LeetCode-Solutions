/*
 Problem:
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> solution;
        if(matrix.empty())  return solution;
            
        int iStart = 0, iEnd = matrix.size(), jStart = 0, jEnd = matrix[0].size();
        
        for(int k = 1; iStart < iEnd && jStart < jEnd; k++) {
            if(k%4 == 1) {
                for(int j = jStart; j < jEnd; j++)
                    solution.push_back(matrix[iStart][j]);
                iStart++;
            } else if(k%4 == 2) {
                for(int i = iStart; i < iEnd; i++)
                    solution.push_back(matrix[i][jEnd-1]);
                jEnd--;
            } else if(k%4 == 3) {
                for(int j = jEnd-1; j >= jStart; j--)
                    solution.push_back(matrix[iEnd-1][j]);
                iEnd--;
            } else {
                for(int i = iEnd-1; i >= iStart; i--)
                    solution.push_back(matrix[i][jStart]);
                jStart++;
            }    
        }
        return solution;
    }
};
