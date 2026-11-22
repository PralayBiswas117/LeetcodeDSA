class Solution {
public:
    bool checkString(string s) {
        return ranges::is_sorted(s);
    }
};