class Solution {
public:
//go from left and right if at left and right value is not equal once slip left and right  and if any of them is palindrom then ok otherwise false;
    bool isPalindrome (string sub)
    {
        int l=0,r=sub.size()-1;
        while(l<r)
        {
            if(sub[l]!=sub[r])  return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int left=0,right=n-1;
        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                return isPalindrome(s.substr(left+1,right-left))|| isPalindrome(s.substr(left,right-left));
            }
        }
        return true;
    }
};