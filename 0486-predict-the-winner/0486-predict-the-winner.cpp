#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i] will store the max score difference for the subarray starting at index i
        vector<int> dp(n);
        
        // Base case: If the array length is 1, the player just takes the single element.
        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i];
        }
        
        // Build the DP table bottom-up, starting from subarrays of length 2 up to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // Ending index of the current subarray
                
                // Maximize the score difference:
                // Option 1: Pick nums[i], subtract the best the opponent can do from i+1 to j
                // Option 2: Pick nums[j], subtract the best the opponent can do from i to j-1
                dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }
        
        // Player 1 wins if the final score difference is greater than or equal to 0
        return dp[0] >= 0;
    }
};