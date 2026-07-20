class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int start, vector<int>& current) {
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);

            backtrack(nums, i + 1, current);

            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        backtrack(nums, 0, current);

        return ans;
    }
};