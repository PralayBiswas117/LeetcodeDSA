typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
const int MOD = (int) 1e9 + 7;

template<ll mod = MOD>
struct mint {
    ll x;

    mint() : x(0) {}

    mint(ll _x) {
        _x %= mod;
        if (_x < 0) _x += mod;
        x = _x;
    }

    mint &operator+=(const mint &a) {
        x += a.x;
        if (x >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint &a) {
        x += mod - a.x;
        if (x >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint &a) {
        x = (ull) x * a.x % mod;
        return *this;
    }

    mint pow(ll pw) const {
        mint res = 1;
        mint cur = *this;
        while (pw) {
            if (pw & 1) res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }

    mint inv() const {
        assert(x != 0);
        ll t = x;
        ll res = 1;
        while (t != 1) {
            ll z = mod / t;
            res = (ull) res * (mod - z) % mod;
            t = mod - t * z;
        }
        return res;
    }

    mint &operator/=(const mint &a) {
        return *this *= a.inv();
    }

    mint operator+(const mint &a) const {
        return mint(*this) += a;
    }

    mint operator-(const mint &a) const {
        return mint(*this) -= a;
    }

    mint operator*(const mint &a) const {
        return mint(*this) *= a;
    }

    mint operator/(const mint &a) const {
        return mint(*this) /= a;
    }

    bool operator==(const mint &a) const {
        return x == a.x;
    }

    bool operator!=(const mint &a) const {
        return x != a.x;
    }

    bool operator<(const mint &a) const {
        return x < a.x;
    }

    friend ostream &operator<<(ostream &out, const mint &m) {
        out << m.x;
        return out;
    }
};

using Mint = mint<MOD>;


class Solution {
public:

    Mint dp[201][(int) 2e4 + 3];
    int freq[(int) 2e4 + 3];
    int countSubMultisets(vector<int>& a, int l, int r) {
    vi b;
    for (auto x: a) {
        if (freq[x] == 0 && x != 0)
            b.emplace_back(x);
        freq[x]++;

    }

    int n = b.size();
    for (int j = 0; j <= r; ++j) 
        dp[n][j] = 1;
    

    for (int i = n-1; i >= 0; --i){
        for (int j = 0; j <= r; ++j){
            dp[i][j] = dp[i+1][j];
            if (j-b[i] >= 0) {
                dp[i][j] += dp[i][j - b[i]];
                if (j-(freq[b[i]]+1)*b[i] >= 0)
                    dp[i][j] -= dp[i+1][j-(freq[b[i]]+1)*b[i]];
            }
        }
    }


    return ((dp[0][r] - (l-1 >= 0 ? dp[0][l-1] : 0))*(1+freq[0])).x;
    }
};