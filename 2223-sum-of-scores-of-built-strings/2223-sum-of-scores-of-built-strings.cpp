class Solution {
public:
    long long sumScores(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        vector<int>z(n,0);
        for(int i=1;i<n;i++){
            if(i>r){
                l=i;
                r=i;
                while(r<n && s[r-l]==s[r]) r++;
                z[i]=r-l;
                r=r-1;
            }
            else{
                int k=i-l;
                if(z[k]<r-i+1){
                    z[i]=z[k];
                }
                else{
                    l=i;
                    while(r<n && s[r-l]==s[r]) r++;
                    z[i]=r-l;
                    r=r-1;
                }
            }
        }
        long long ans=n;
        for(int x:z)ans+=x;
        return ans;
    }
};