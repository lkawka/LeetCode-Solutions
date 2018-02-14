class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int solution = 0, N = A.size();
        unordered_map<int, int> CDsums;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                CDsums[C[i]+D[j]]++;
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                solution += CDsums[-(A[i]+B[j])];
            }
        }
        
        
        return solution;
    }
};