class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(
            maxVal + 1,
            vector<int>(maxVal + 1, 0)
        );

        for (int x : nums) {
            auto next = dp;

            next[x][0] = (next[x][0] + 1) % MOD;
            next[0][x] = (next[0][x] + 1) % MOD;

            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    if (dp[g1][g2] == 0)
                        continue;

                    int a = (g1 == 0 ? x : gcd(g1, x));
                    int b = (g2 == 0 ? x : gcd(g2, x));

                    next[a][g2] =
                        (next[a][g2] + dp[g1][g2]) % MOD;

                    next[g1][b] =
                        (next[g1][b] + dp[g1][g2]) % MOD;
                }
            }

            dp = move(next);
        }

        long long answer = 0;

        for (int g = 1; g <= maxVal; g++) {
            answer = (answer + dp[g][g]) % MOD;
        }

        return answer;
    }
};