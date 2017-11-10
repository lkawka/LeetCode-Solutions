class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0, backIterator=0;
        bitset<200> been;
        for(int i = 0;i < s.length(); i++){
            if(been[s[i]])
            {
                while(s[backIterator] != s[i])
                {
                    been[s[backIterator]] = false;
                    backIterator++;
                }
                backIterator++;
            }
            been[s[i]]=true;
            result = max(result, i-backIterator+1);
        }
        return result;
    }
};