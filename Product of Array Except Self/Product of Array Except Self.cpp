class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size(), product = 1;
        vector<int> solution(N, 1);
        
        for(int i = 0; i < N; i++) {
            solution[i] *= product;
            product *= nums[i];
        }
        
        product = 1;
        
        for(int i = N-1; i >= 0; i--) {
            solution[i] *= product;
            product *= nums[i];
        }
        
        return solution;
    }
};