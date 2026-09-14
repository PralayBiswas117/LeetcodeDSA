class Solution {
public:
bool isplaindrome(long long i,long long j,string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    long long part(string &s,long long i,vector<long long>&dp){
        if(i==s.length()) return 0;
        if(dp[i]!=-1)return dp[i];
        long long minc=1e9;
        for(long long j=i;j<s.length();j++){
            long long cost=1e9;
            if(isplaindrome(i,j,s)){
                 cost=1+part(s,j+1,dp);
            }
            minc=min(cost,minc);
        }
        return dp[i]=minc;
    }
    int minCut(string s) {
        long long n=s.length();
        vector<long long>dp(n+1,-1);
        return part(s,0,dp)-1;
    }
};