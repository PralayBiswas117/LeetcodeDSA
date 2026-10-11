class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long sum = 0;
        for(int i= nums.size()-1 ; i>=0 ; i--){
            if(nums[i] <= sum) sum += nums[i];
            else sum = nums[i];
        }
        return sum;
    }
};