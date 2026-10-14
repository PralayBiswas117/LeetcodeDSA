class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int op = 1000000;
        for(int i = 0; i < nums1.size(); i++)
        {
            ans += abs(nums1[i] - nums2[i]);
            int n = nums2.back();

            if((nums1[i] <= n && nums2[i] >= n) || (nums2[i] <= n && nums1[i] >= n))
                op = 0;
            else if(abs(nums2[i] - n) < abs(nums1[i] - n))
                op = min(op, abs(nums2[i] - n));
            else
                op = min(op, abs(nums1[i] - n));
        }
        return ans + 1 + op;
    }
};
