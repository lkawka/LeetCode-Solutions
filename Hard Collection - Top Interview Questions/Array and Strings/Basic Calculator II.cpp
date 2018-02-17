/*
 Problem:
 Implement a basic calculator to evaluate a simple expression string.
 
 The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 
 You may assume that the given expression is always valid.
 
 Some examples:
 "3+2*2" = 7
 " 3/2 " = 1
 " 3+5 / 2 " = 5
 Note: Do not use the eval built-in library function.
*/

class Solution {
private:
    struct elm {
        char op = '#';
        int num;
    };
    typedef list<elm> LE;
    
    inline int stringToInt(string& s) {
        int solution = s[0]-'0', N = s.size();
        for(int i = 1; i < N; i++) {
            solution = (solution<<3)+(solution<<1);
            solution += s[i]-'0';
        }
        return solution;
    }
    
    inline LE stringToList(string& s) {
        int N = s.size();
        LE solution;
        string prev = "";
        for(int i = 0; i < N; i++) {
            elm e;
            if(s[i] >= '0' && s[i] <= '9') {
                prev += s[i];
            } else {
                if(prev != "") {
                    e.num = stringToInt(prev);
                    solution.push_back(e);
                    prev = "";
                }
                if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-') {
                    e.op = s[i];
                    solution.push_back(e);
                }
            }
        }
        if(prev != "") {
            elm e;
            e.num = stringToInt(prev);
            solution.push_back(e);
            prev = "";
        }
        
        return solution;
    }
    typedef LE::iterator LEI;
    
public:
    int calculate(string s) {
        LE l = stringToList(s);
        
        for(LEI it = l.begin(); it != l.end(); it++) {
            char c = it->op;
            if(c == '*' || c == '/') {
                int num1 = prev(it, 1)->num, num2 = next(it, 1)->num;
                l.erase(next(it, 1));
                if(c == '*') it->num = num1*num2;
                else it->num = num1/num2;
                l.erase(prev(it, 1));
                it->op = '#';
            }
        }
        
        for(LEI it = l.begin(); it != l.end(); it++) {
            char c = it->op;
            if(c != '#') {
                int num1 = prev(it, 1)->num, num2 = next(it, 1)->num;
                l.erase(next(it, 1));
                if(c == '+') it->num = num1+num2;
                else it->num = num1-num2;
                l.erase(prev(it, 1));
                it->op = '#';
            }
        }
        return l.front().num;
    }
};
