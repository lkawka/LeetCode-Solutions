/*
 Problem:
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 
 Solve it without division and in O(n).
 
 For example, given [1,2,3,4], return [24,12,8,6].
 
 Follow up:
 Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

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
