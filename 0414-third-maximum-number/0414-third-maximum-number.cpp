class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = -2147483649, second = -2147483649, third = -2147483649;
        std::unordered_set<int> prevThirds;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= first) {
                if (nums[i] != first) {
                    third = second;
                    second = first;
                    first = nums[i];
                }
            } else if (nums[i] >= second) {
                if (nums[i] != second) {
                    third = second;
                    second = nums[i];
                }
            } else if (nums[i] >= third) {
                if (i == nums.size() - 1 && prevThirds.contains(nums[i])) {
                    goto here;
                }
                third = nums[i];
            }
        }
        if (third == -2147483649) {
        here:
            return first;
        }
        return third;
    }
};