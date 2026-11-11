class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans = nums[0] - nums[1], prefix_sum = 0;
        int n = nums.size(), Min = nums[n - 1];
        for(int i = 0; i < n - 1; i++) prefix_sum += nums[i];
        for(int i = n - 2; i >= 0; i--) {
            ans = max(ans, prefix_sum - Min);
            Min = min(Min, nums[i]);
            prefix_sum -= nums[i];
        }
        return ans;
    }
};