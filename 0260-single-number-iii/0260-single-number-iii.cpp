class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xr=0;
        for(int i=0;i<nums.size();i++){
             xr^=nums[i];
        }
        int right_bit=(xr&(xr-1))^(xr);
        int buck_0=0;
        int buck_1=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i] & right_bit){
                  buck_1=buck_1^nums[i];
             }
             else{
                buck_0=buck_0^nums[i];
             }
        }
        return {buck_0,buck_1};
    }
};