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