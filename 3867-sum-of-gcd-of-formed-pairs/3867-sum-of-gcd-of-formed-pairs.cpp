class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd;
        int mx = 0;

        // Step 1: Build prefixGcd
        for (int x : nums) {
            mx = max(mx, x);
            prefixGcd.push_back(gcd(x, mx));
        }

        // Step 2: Sort
        sort(prefixGcd.begin(), prefixGcd.end());

        // Step 3: Pair smallest with largest
        long long ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }

        return ans;
    }
};