class Solution {
public:
    //Approach : Direct Indexing / Array Mapping

    //Time Complexity = O(n) =>
    /* We traverse the string once, (n elements)
    * Each assignment ans[indices[i]] = s[i] takes O(1).
    * So : O(n) * O(1) = O(n)
    */

    //Space Complexity = O(n) =>
    /* We create ans string of size n.
    * No other significant extra space.
    */


    string restoreString(string s, vector<int>& indices) {
        
        int n = s.length();

        string ans(n, ' ');//n sized string filled with spaces to store the output string

        for(int i = 0; i < n; i++){

            ans[indices[i]] = s[i];
        }

        return ans;
    }
};