class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> first, last, count;
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (first.find(nums[i]) == first.end())
                first[nums[i]] = i;


            last[nums[i]] = i;
            count[nums[i]]++;
        }

        for (auto it : count) {
            maxi = max(maxi, it.second);
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            if (count[nums[i]] == maxi) {
                ans = min(ans, last[nums[i]] - first[nums[i]] + 1);
            }
        }
        return ans;
    }
};