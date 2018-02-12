class Solution {
public:
    string frequencySort(string s) {
        string solution = "";
        int n = 300;
        unordered_map<char, int> frequency;
        vector<string> bucket(s.size()+1, "");
        for(char c: s)
            frequency[c]++;
        for(auto& it: frequency)
            bucket[it.second].append(it.second, it.first);
        for(int i = s.size(); i > 0; i--) 
            if(!bucket[i].empty())
                solution.append(bucket[i]);
        return solution;
    }
};