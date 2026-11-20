class Solution {
private:
    int findMaxOpsHelper(std::vector<int>& nums, int left, int right, int previousSum, std::vector<std::vector<int>>& memoization) {
        if (left >= right)
            return 0;
        if (memoization[left][right] != 0)
            return memoization[left][right];

        int maxOps = 0;
        if (nums[left] + nums[left + 1] == previousSum)
            maxOps = std::max(maxOps, findMaxOpsHelper(nums, left + 2, right, previousSum, memoization) + 1);
        if (nums[left] + nums[right] == previousSum)
            maxOps = std::max(maxOps, findMaxOpsHelper(nums, left + 1, right - 1, previousSum, memoization) + 1);
        if (nums[right] + nums[right - 1] == previousSum)
            maxOps = std::max(maxOps, findMaxOpsHelper(nums, left, right - 2, previousSum, memoization) + 1);

        return memoization[left][right] = maxOps;
    }
public:
    int maxOperations(vector<int>& nums) {
        int maxOperations = 0;
        int len = nums.size();
        std::vector<std::vector<int>> memoization(len, std::vector<int>(len, 0));
        int start = 0;
        int end = len - 1;

        maxOperations = std::max(maxOperations,
                findMaxOpsHelper(nums, start + 2, end, nums[start] + nums[start + 1], memoization) + 1);
        maxOperations = std::max(maxOperations,
                findMaxOpsHelper(nums, start + 1, end - 1, nums[start] + nums[end], memoization) + 1);
        maxOperations = std::max(maxOperations,
                findMaxOpsHelper(nums, start, end - 2, nums[end] + nums[end - 1], memoization) + 1);

        return maxOperations;
    }
};