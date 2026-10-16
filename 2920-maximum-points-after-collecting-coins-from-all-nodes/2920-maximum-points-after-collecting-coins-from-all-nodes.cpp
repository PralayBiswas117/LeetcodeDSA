class Solution {
public:
    vector<vector<int>>adj;
    vector<int>pow;
    int dfs(vector<int>&coins,int k,int u,int par,int level){
        int op1=INT_MIN;
        if(level==0) op1=coins[u]-k;
        int op2=level>=14?0:floor(coins[u]/pow[level+1]);
        for(int &v:adj[u]){
            if(v==par) continue;
            if(level==0)op1+=(dfs(coins,k,v,u,level));
            if(level<=14) op2+=(dfs(coins,k,v,u,level+1));
        }
        return max(op1,op2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=coins.size();
        adj.resize(n);
        for(auto&e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pow.resize(17,1);
        for(int i=1;i<=16;i++) pow[i]=pow[i-1]*2;
        return dfs(coins,k,0,-1,0);
    }
};
/*
phli chij ye h ki agar mainr ek baar /2 wala use kar liya operation to fr hm op 1 (-k) wala use hee nhi kar skte 
fr dusri baat ye cost[i]->10^4 th h to maxm 15 depth tak 10^4 se jyada bn jata h to divide karne pe 0 hee aayega to dfs call karne ka koi matlab nhi hoga 
*/