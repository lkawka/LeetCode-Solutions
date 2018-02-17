/*
 Problem:
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 
 Your algorithm should run in O(n) complexity.
*/

class Solution {
private:
    int solution;
    unordered_map<int, int> index, solutions;
    void cons(int s) {
        if(solutions[s] > 0) {
            return;
        } else if(index[s+1]) {
            cons(s+1);
            solutions[s] = solutions[s+1]+1;
        } else {
            solutions[s] = 1;
        }
        solution = max(solution, solutions[s]);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        solution = 0;
        for(int i = 0; i < N; i++)
            index[nums[i]] = 1;
        for(int i = 0; i < N; i++)
            cons(nums[i]);
        return solution;
    }
};
