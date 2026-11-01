class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto x: s){
            mp[x]++;
        }
        string ans="";
        while(!mp.empty()){
            char maxChar=0;
            int maxFreq=0;
            for(auto it : mp) {
                if(it.second > maxFreq) {
                    maxFreq = it.second;
                    maxChar = it.first;
                }
            }
            while(maxFreq--) {
                ans.push_back(maxChar);
            }
            mp.erase(maxChar);
        }
        return ans;
    }
};