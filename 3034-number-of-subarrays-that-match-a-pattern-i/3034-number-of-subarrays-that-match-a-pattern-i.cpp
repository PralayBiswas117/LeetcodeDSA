class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;

        for(int i = 0; i + m < n; i++) {
            bool ok = true;

            for(int k = 0; k < m; k++) {
                if(pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) {
                    ok = false;
                    break;
                }
                else if(pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) {
                    ok = false;
                    break;
                }
                else if(pattern[k] == -1 && nums[i + k + 1] >= nums[i + k]) {
                    ok = false;
                    break;
                }
            }

            if(ok) count++;
        }

        return count;
    }
};