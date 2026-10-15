class Solution {
public:
    int n;
    int T;
    int ans;
    int dp[1001][1001];
    int f(vector<int>&nums,int i,int sum){
        if(sum>T) return -1e5;
        if(sum==T) return 0;
        if(i>=n) return -1e5;

        if(dp[i][sum]!=-1) return dp[i][sum];

        int take=1+f(nums,i+1,sum+nums[i]);
        int skip=f(nums,i+1,sum);

        return dp[i][sum]=max(take,skip);

    }
    int lengthOfLongestSubsequence(vector<int>&nums,int t){
        n=nums.size();
        T=t;
        ans=0;
        memset(dp,-1,sizeof(dp));
        ans=f(nums,0,0);
        if(ans<=0) return -1;
        return ans;
        
    }
};