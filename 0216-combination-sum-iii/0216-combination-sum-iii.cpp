class Solution {
    void f(int val,int k,int target,vector<int>& temp,vector<vector<int>>& ans){
        //base case
         if(k==0 && target==0){
            ans.push_back(temp);
            return;
         }
         if(k==0 || val<1) return;
      //recursion
      if(val<=target){
        temp.push_back(val);
        f(val-1,k-1,target-val,temp,ans);
        temp.pop_back();
      }
      f(val-1,k,target,temp,ans);
    } 
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int lower=k*(k+1)/2,upper=45-(9-k)*(10-k)/2;
        if(n<lower || n>upper) return ans;
        vector<int> temp;
        f(9,k,n,temp,ans);
        return ans;
    }
};