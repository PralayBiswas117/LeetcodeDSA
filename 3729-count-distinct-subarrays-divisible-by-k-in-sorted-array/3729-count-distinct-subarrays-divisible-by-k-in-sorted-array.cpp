#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        long long s = 0;
        unordered_map<long long, long long> dp;
        dp[0] = 1;
        long long ans = 0;
        long long cnts = 0;
        int prev = -1;

        for (int i : nums) {
            // Update same-element count
            if (i == prev) {
                cnts += 1;
            } else {
                cnts = 1;
                prev = i;
            }

            // Find the LCM relation between i and k
            long long g = gcd((long long)k, (long long)i);
            long long fact = ( (long long)k / g );

            // Remove subarrays that have already appeared
            long long subt = cnts / fact;
            if (cnts % fact == 0) subt -= 1;

            // Standard prefix-sum remainder logic
            s = (s + i) % k;

            if (!dp.count(s)) dp[s] = 0;

            ans += dp[s] - subt;
            dp[s] += 1;
        }

        return ans;
    }
};