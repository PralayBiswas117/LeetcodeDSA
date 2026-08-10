class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for (int curr = n; curr > 1; curr--) {
            int idx = 0;

            while (arr[idx] != curr)
                idx++;

            if (idx == curr - 1)
                continue;

            if (idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx + 1);
            }

            reverse(arr.begin(), arr.begin() + curr);
            ans.push_back(curr);
        }

        return ans;
    }
};