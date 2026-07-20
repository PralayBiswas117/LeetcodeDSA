class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0; // Best answer before previous house
        int prev1 = 0; // Best answer up to previous house

        for (int money : nums) {
            int current = max(prev1, prev2 + money);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};