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