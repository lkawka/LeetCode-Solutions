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