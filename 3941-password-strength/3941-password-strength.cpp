class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char> s;
        int n = password.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            s.insert(password[i]);
        }

        for (auto ele : s) {
            if (ele >= 'a' && ele <= 'z')
                ans += 1;
            else if (ele >= 'A' && ele <= 'Z')
                ans += 2;
            else if (ele >= '0' && ele <= '9')
                ans += 3;
            else
                ans += 5;
        }

        return ans;
    }
};