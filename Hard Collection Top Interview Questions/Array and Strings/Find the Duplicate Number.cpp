class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while(start < end) {
            int middle = (start+end)>>1, lessCount = 0;
            for(int num: nums) {
                if(num <= middle)
                    lessCount++;
            }
            if(lessCount > middle)
                end = middle;
            else
                start = middle + 1;
        }
        return start;
    }
};