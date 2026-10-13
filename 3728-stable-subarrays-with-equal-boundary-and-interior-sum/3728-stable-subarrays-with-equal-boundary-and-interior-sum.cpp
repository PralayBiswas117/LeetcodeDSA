class Solution {
public:
    using ll = long long;
    long long countStableSubarrays(vector<int>& a) {
        ll n = a.size(), res = 0, pre = 0;
        unordered_map<ll, unordered_map<ll, ll>> mpp;

        for (int i = 0; i < n; i++) {
            if (mpp.count(a[i]) and mpp[a[i]].count(pre - a[i])) {
                res += mpp[a[i]][pre - a[i]];
            }
            pre += a[i];
            mpp[a[i]][pre]++;
            if (i > 0 && a[i] == 0 && a[i - 1] == 0) {
                res--;
            }
        }
        return res;
    }
};