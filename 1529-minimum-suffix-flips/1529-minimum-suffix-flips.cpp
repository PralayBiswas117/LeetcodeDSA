class Solution {
public:
    int minFlips(string target) {
        int curr = '0';
        int ans = 0;

        for(auto c : target){
            if(c != curr){
                curr = c;
                ans++;
            }
        }
        return ans;
    }
};