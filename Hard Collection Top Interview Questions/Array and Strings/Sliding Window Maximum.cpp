class Solution {
#define num first
#define index second
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        deque<pair<int, int>> q;
        vector<int> solution; 
        
        if(k == 0)  return solution;
        
        for(int i = 0; i < k; i++) {
            if(!q.empty() && nums[i] >= q.front().num) {
                while(!q.empty() && nums[i] >= q.front().num)
                    q.pop_front();
                q.push_front({nums[i], i});
            } else {
                while(!q.empty() && nums[i] >= q.back().num)
                    q.pop_back();
                q.push_back({nums[i], i});
            }
        }
        
        solution.push_back(q.front().num);

        for(int i = 1; i+k-1 < N; i++) {
            while(!q.empty() && q.front().index < i)
                q.pop_front();
            if(!q.empty() && q.front().num <= nums[i+k-1])
                q.front() = {nums[i+k-1], i+k-1};
            else {
                while(!q.empty() && (q.back().num <= nums[i+k-1] || q.back().index < i))
                    q.pop_back();
                q.push_back({nums[i+k-1], i+k-1});
            }
            solution.push_back(q.front().num);
        }
        
        return solution;
    }
};