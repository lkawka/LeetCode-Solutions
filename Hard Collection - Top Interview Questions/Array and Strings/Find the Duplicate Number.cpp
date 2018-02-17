/*
 Problem:
 Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 
 Note:
 You must not modify the array (assume the array is read only).
 You must use only constant, O(1) extra space.
 Your runtime complexity should be less than O(n2).
 There is only one duplicate number in the array, but it could be repeated more than once.
*/

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
