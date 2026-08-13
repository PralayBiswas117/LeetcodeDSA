class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int>& nums) { original = nums; }
    vector<int> reset() { return original; }

    vector<int> shuffle() {
        vector<int> arr = original;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int j = rand() % n;
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};