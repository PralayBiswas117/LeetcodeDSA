class Solution {
public:
    bool isGood(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        set<int>st(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        n-=1;
        int act=(n*(n+1))/2;
        act+=n;
        return sum==act && st.size()==n && maxi==n;
    }
};