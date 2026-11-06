class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<int>dp(sum+1,INT_MAX);
        dp[0]=0;
        /*
        6,3
        => 6/2 = 3
        => 3/2 = 1

        6,3
        => 3/2 = 1
        => 1*2 = 2
        6+2 =8
        */
        for(int i=0;i<n;i++){
            int val = nums[i];

            vector<pair<int,int>>curr;
            unordered_map<int,bool>findbyval;
            long long x = val;
            int count = 0;
            
            
            while(x <= sum){
                curr.push_back({x,count});
                findbyval[x] = true;
                x *= 2;
                count++;
            }

            x = val;
            count = 0;

            while(x > 1){
                if(x%2==1){
                    int a = (x/2);
                    int val = count + 1;
                    while(a<=sum){
                        a = a*2;
                        val++;
                        if(findbyval[a]==false){
                            curr.push_back({a,val});
                            findbyval[a] = true;
                        }
                    }
                }
                x /= 2;
                count++;
                
                if(x <= sum){
                    curr.push_back({x,count});
                    findbyval[x] = true;
                }
            }

            vector<int> next = dp;

            for(int j=0;j<=sum;j++){
                if(dp[j] == INT_MAX){
                    continue;
                }

                for(auto p : curr){
                    int x = p.first;
                    int count = p.second;

                    if(j+x <= sum){
                        next[j+x] = min(next[j+x],dp[j]+count);
                    }
                }
            }
            dp = next;
        }

        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};