/*
 Problem:
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int solution = 0;
        int front = 0, back = height.size()-1;
        
        while(front < back) {
            int newHeight = min(height[front], height[back]);
            solution = max(solution, newHeight*(back-front));
            
            while(height[front] <= newHeight && front < back)
                front++;
            while(height[back] <= newHeight && front < back)
                back--;
        }
        return solution;
    }
};
