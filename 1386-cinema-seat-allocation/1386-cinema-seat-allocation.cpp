class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> row;
        
        // Store reserved seats using bitmask
        for (auto &seat : reservedSeats) {
            int r = seat[0];
            int s = seat[1];
            
            row[r] |= (1 << (s - 1));
        }
        
        // Rows with no reservations can always fit 2 groups
        int ans = (n - row.size()) * 2;
        
        // Masks for the three possible groups
        int left  = 0b0000011110;  // seats 2-5
        int middle = 0b0001111000; // seats 4-7
        int right = 0b0111100000;  // seats 6-9
        
        // Process only rows having reservations
        for (auto &[r, mask] : row) {
            
            bool leftAvailable = (mask & left) == 0;
            bool middleAvailable = (mask & middle) == 0;
            bool rightAvailable = (mask & right) == 0;
            
            if (leftAvailable && rightAvailable) {
                // Two groups can sit
                ans += 2;
            }
            else if (leftAvailable || middleAvailable || rightAvailable) {
                // At least one group can sit
                ans += 1;
            }
        }
        
        return ans;
    }
};