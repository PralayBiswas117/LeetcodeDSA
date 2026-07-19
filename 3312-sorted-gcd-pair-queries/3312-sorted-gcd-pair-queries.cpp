class Solution {
public:
    vector<int> gcdValues(vector<int>& nums,
                           vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        // frequency[x] = how many times x appears
        vector<int> frequency(mx + 1, 0);

        for (int x : nums) {
            frequency[x]++;
        }

        // exactPairs[g] = number of pairs whose GCD is exactly g
        vector<long long> exactPairs(mx + 1, 0);

        // Process from large GCD to small GCD
        for (int g = mx; g >= 1; g--) {

            long long count = 0;

            // Count numbers divisible by g
            for (int multiple = g;
                 multiple <= mx;
                 multiple += g) {

                count += frequency[multiple];
            }

            // All pairs where both numbers are divisible by g
            exactPairs[g] = count * (count - 1) / 2;

            // Remove pairs whose GCD is a larger multiple of g
            for (int multiple = 2 * g;
                 multiple <= mx;
                 multiple += g) {

                exactPairs[g] -= exactPairs[multiple];
            }
        }

        // Prefix sum:
        // prefix[g] = number of pairs with GCD <= g
        vector<long long> prefix(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            prefix[g] = prefix[g - 1] + exactPairs[g];
        }

        vector<int> answer;

        for (long long q : queries) {
            // First GCD value whose prefix count > q
            int gcdValue =
                upper_bound(prefix.begin(),
                            prefix.end(),
                            q) - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};