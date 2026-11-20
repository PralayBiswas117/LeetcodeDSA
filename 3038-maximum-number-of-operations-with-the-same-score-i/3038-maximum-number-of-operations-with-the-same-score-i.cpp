class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int i=0,j=1,count=0;
        int prev = nums[i]+nums[j];
        while(j<nums.size()){
            int sum = nums[i]+nums[j];
            if(sum==prev) count++;
            else break;
            i+=2;
            j+=2;
        }
        return count;
    }
};