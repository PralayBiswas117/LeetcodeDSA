class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        vector<int>temp(n);

        int i = 1 ;
        int j = n - 1;

        while(i < n){
           temp[i] = nums[j];
           i+=2;
           j--;
        } 
        //get i to starting position 
        i = 0;

        while(i < n){
            temp[i] = nums[j];
            i+=2;
            j--;
        }
        
         j = 0;
        while(j < n){
          nums[j] = temp[j];
          j++;
        }
        
       
    }
};