class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            curr += 1LL * i * nums[i];
        }

        long long ans = curr;

        for (int i = 1; i < n; i++) {
            curr = curr + sum - 1LL * n * nums[n - i];
            ans = max(ans, curr);
        }

        return (int)ans;
    }
};