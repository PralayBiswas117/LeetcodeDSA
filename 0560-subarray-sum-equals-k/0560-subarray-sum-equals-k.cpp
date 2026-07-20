class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Prefix sum 0 occurs once
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            if (freq.find(prefixSum - k) != freq.end()) {
                count += freq[prefixSum - k];
            }

            freq[prefixSum]++;
        }

        return count;
    }
};