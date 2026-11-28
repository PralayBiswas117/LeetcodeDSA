class Solution {
public:
const int MOD = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k>0)
        {
            k--;
            int x = pq.top();
            pq.pop();
            pq.push(x+1);
        }
        long ans = 1;
        while(!pq.empty())
        {
            ans = (ans * pq.top())%MOD;
            pq.pop();
        }
        return ans%MOD;
    }
//please upvote...
};