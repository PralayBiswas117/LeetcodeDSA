class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int i=0,j=0;
        int res=0;
        while(i<g.size()&&j<s.size()){
            if(s[j]>=g[i]){
                i++;j++;
                res++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};