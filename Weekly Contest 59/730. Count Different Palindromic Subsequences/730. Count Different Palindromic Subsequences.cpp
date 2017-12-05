class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int solution = 0;
        int n = S.size(), mod = 1e9+7;
        
        auto dpPointer = new vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(n)));
        auto& dp = *dpPointer;
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                for(int k = 0; k < 4; k++) {
                    char x = 'a'+k;
                    if(i == j) {
                        dp[k][i][j] = (S[i] == x ? 1 : 0);
                    } else {
                        if(S[i] != x) {
                            dp[k][i][j] = dp[k][i+1][j];
                        } else if(S[j] != x) {
                            dp[k][i][j] = dp[k][i][j-1];
                        } else {
                            dp[k][i][j] = 2;
                            if(j > i+1) {
                                for(int m = 0; m < 4; m++) {
                                    dp[k][i][j] += dp[m][i+1][j-1];
                                    dp[k][i][j] %= mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < 4; i++) {
            solution += dp[i][0][n-1];
            solution %= mod;
        }
        
        return solution;
    }
};