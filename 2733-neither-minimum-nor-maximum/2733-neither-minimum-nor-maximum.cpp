class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3){
            return -1;
        }
        long long maximum = LLONG_MIN;
        long long minimum = LLONG_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maximum){
                maximum = nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minimum){
                minimum = nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] != maximum && nums[i] != minimum){
                return nums[i];
            }
        }
        return -1;
    }
};