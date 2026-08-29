class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> max_res;
        
        // Step 1: Guess the split
        // i represents the number of digits we take from nums1
        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            
            // Step 2: Squeeze the best digits from each array
            vector<int> seq1 = maxArray(nums1, i);
            vector<int> seq2 = maxArray(nums2, k - i);
            
            // Step 3: Merge them
            vector<int> candidate = merge(seq1, seq2);
            
            // Step 4: Compare and keep the champion
            if (candidate > max_res) {
                max_res = candidate;
            }
        }
        
        return max_res;
    }
    
private:
    // Helper to get the largest sequence of length k from a single array
    vector<int> maxArray(const vector<int>& nums, int k) {
        int drop = nums.size() - k; 
        vector<int> stack;
        
        for (int num : nums) {
            while (drop > 0 && !stack.empty() && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        
        stack.resize(k); // Trim any leftover elements if we didn't drop enough
        return stack;
    }
    
    // Helper to merge two sequences to form the maximum number
    vector<int> merge(const vector<int>& seq1, const vector<int>& seq2) {
        vector<int> res;
        int i = 0, j = 0;
        
        while (i < seq1.size() || j < seq2.size()) {
            // Compare the remaining portions of both arrays to handle ties correctly
            if (isGreater(seq1, i, seq2, j)) {
                res.push_back(seq1[i++]);
            } else {
                res.push_back(seq2[j++]);
            }
        }
        return res;
    }
    
    // Helper to check which array has the stronger remaining sequence
    bool isGreater(const vector<int>& seq1, int i, const vector<int>& seq2, int j) {
        while (i < seq1.size() && j < seq2.size() && seq1[i] == seq2[j]) {
            i++;
            j++;
        }
        
        if (j == seq2.size()) return true;
        if (i == seq1.size()) return false;
        
        return seq1[i] > seq2[j];
    }
};