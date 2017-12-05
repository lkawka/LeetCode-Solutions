class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> solution;
        for(int i = left; i <= right; i++) {
            int num = i;
            bool notSolution = false;
            while(num > 0) {
                if(num%10 == 0 || i%(num%10) != 0){
                    notSolution = true;
                    break;
                }
                num /= 10;
            }
            if(!notSolution)
                solution.push_back(i);
        }
        return solution;
    }
};