class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen;
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] > 0) {
                seen.push_back(nums[i]);
                i++;
            } else {
                int idx = seen.size() - 1;
                while (i < n && nums[i] == -1) {
                    if (idx < 0)
                        ans.push_back(-1);
                    else {
                        ans.push_back(seen[idx]);
                        idx--;
                    }
                    i++;
                }
            }
        }
        return ans;
    }
};