class Solution {
public:
    int numOfSubarrays(vector<int>& nums) 
    {
        int MOD = 1000000007, n = nums.size();
        vector<vector<int>> prev(n, vector<int>(2, 0));

        if(nums[0] % 2 == 0)
            prev[0][1] = 1;
        else
            prev[0][0] = 1;

        for(int i = 1; i < n; i++)
        {
            int oddPrev = prev[i-1][0];
            int evenPrev = prev[i-1][1];
            int oddCurr = 0;
            int evenCurr = 0;

            if(nums[i] % 2 == 0)
            {
                oddCurr = oddPrev;
                evenCurr = evenPrev + 1;
            }
            else
            {
                oddCurr = evenPrev + 1;
                evenCurr = oddPrev;
            }

            prev[i][0] = oddCurr;
            prev[i][1] = evenCurr;
        }

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = (sum + prev[i][0]) % MOD;
        }
        return sum;
    }
};