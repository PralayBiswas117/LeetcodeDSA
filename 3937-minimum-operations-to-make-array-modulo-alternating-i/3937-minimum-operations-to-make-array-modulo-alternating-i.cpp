class Solution {
public:
    int f(vector<int>&e,vector<int>&o,int x,int y,int k){
        int ans = 0;
        for(int i=0;i<e.size();i++){
            int p = e[i]/k;
            int q = (p-1)*k + x;
            int r = p*k + x;
            int r1 = (p+1)*k+x;
            ans += min({abs(r-e[i]),abs(q-e[i]),abs(r1-e[i])});
        }
        for(int i=0;i<o.size();i++){
            int p = o[i]/k;
            int r1 = (p+1)*k+y;
            int q = (p-1)*k + y;
            int r = p*k + y;
            // cout<<r1<<" "<<q<<" "<<r<<" "<<o[i];
            ans += min({abs(r-o[i]),abs(q-o[i]),abs(r1-o[i])});
        }
        return ans;
    }
    int minOperations(vector<int>& nums, int k) {
        int ans  = INT_MAX;
        vector<int>e,o;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) e.push_back(nums[i]);
            if(i%2==1) o.push_back(nums[i]); 
        }
        for(int x=0;x<=k;x++){
            for(int y=0;y<=k;y++){
                if(x%k==y%k) continue;
                ans = min(ans,f(e,o,x,y,k));
                // cout<<x<<" "<<y<<" "<<ans<<endl;
            }
        }
        return ans;
    }
};