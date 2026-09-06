class Solution {
public:
    int factorial(int num) {
        if(num<=1) return 1;
        return num*factorial(num-1);
    }
    string getPermutation(int n, int k) {
        string res;
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i]=i+1;
        while(k) {
            int n=arr.size(),index;
            if(k==1) {
                for(int i=0; i<n; i++) res+=arr[i]+'0';
                break;
            }
            int fact=factorial(n-1);
            if(k%fact) index=(k/fact);
            else index=(k/fact)-1;
            res+=arr[index]+'0';
            arr.erase(arr.begin() + index);
            if(k%fact) k%=fact;
            else k=fact;
        }
        return res;
    }
};