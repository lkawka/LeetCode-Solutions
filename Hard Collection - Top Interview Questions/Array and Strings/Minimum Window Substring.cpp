/*
 Problem:
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 
 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".
 
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
private:
    int shouldBe[150], currently[150], ok = 0;
    
    inline void handleOK(char c, bool adding) {
        if(adding) {
            if(currently[c] < shouldBe[c])
                ok++;
            currently[c]++;
        } else {
            if(currently[c] <= shouldBe[c])
                ok--;
            currently[c]--;
        }
    }
public:
    string minWindow(string s, string t) {
        int NS = s.size(), NT = t.size(), minn = 1e9, minPointer = 0;
        int backPointer = 0;
        
        for(int i = 0; i < NT; i++)
            shouldBe[t[i]]++;
        
        for(int i = 0; i < NS; i++) {
            while(ok != NT && backPointer < NS) {
                handleOK(s[backPointer], true);
                backPointer++;
            }
            if(ok == NT) {
                //printf("i: %d, b_p: %d\n", i, backPointer);
                if(backPointer-i < minn) {
                    minn = backPointer-i;
                    minPointer = i;
                }
            }
            handleOK(s[i], false);
        }
        
        if(minn == 1e9)
            return "";
        return s.substr(minPointer, minn);
    }
};
