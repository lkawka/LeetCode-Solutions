class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashMap;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            int numberToFind=target-nums[i];
            if(hashMap[numberToFind]>0)
            {
                result.push_back(hashMap[numberToFind]-1);
                result.push_back(i);
                break;
            }
            hashMap[nums[i]]=i+1;
        }
        return result;
    }
};