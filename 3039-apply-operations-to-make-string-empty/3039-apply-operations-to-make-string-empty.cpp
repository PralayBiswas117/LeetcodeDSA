class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char , int> freq ;
        int maxFreq = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            maxFreq = max(maxFreq , ++freq[s[i]]);
        }

        string ans = "";
        unordered_map<char , int> currMap;
        for(int i = 0 ; i < s.size() ; i++){
            currMap[s[i]]++;
            if(maxFreq == currMap[s[i]]){
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};