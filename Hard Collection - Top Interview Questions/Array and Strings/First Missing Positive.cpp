/*
 Problem:
 Given an unsorted integer array, find the first missing positive integer.
 
 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 
 Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int solution = 1;
        unordered_map<int, int> seen;
        for(auto& num: nums) {
            if(num > 0) {
                seen[num] = 1;
                while(seen[solution]) {
                    solution++;
                }
            }
        }
        return solution;
    }
};
