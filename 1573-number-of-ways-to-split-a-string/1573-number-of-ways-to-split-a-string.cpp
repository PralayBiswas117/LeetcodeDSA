class Solution {
public:
    using ll = long long;
    const int mod = 1000000007;

    int numWays(string s) {
        int n = s.size();

        if(n < 3)
            return 0;

        int cnt = 0;

        for(auto c : s) {
            if(c == '1') {
                cnt++;
            }
        }

        if(cnt % 3 != 0) {
            return 0;
        }

        if(cnt == 0) {
            ll x = n - 1;
            return (1LL * x * (x - 1) / 2) % mod;
        }

        int need = cnt / 3;

        vector<int> v;

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                v.push_back(i);
            }
        }

        ll first = v[need] - v[need - 1];
        ll second = v[2 * need] - v[2 * need - 1];

        return (1LL * first * second) % mod;
    }
};