class Solution {
public:
    long long numberOfWays(string s) {
        int prefOne = 0 , prefZero = 0 , suffOne = count(s.begin() , s.end() , '1') , suffZero = count(s.begin() , s.end() , '0');
        long long ans = 0;
        for(char &c : s){
            if(c == '1'){ // count 010
                ans += (1ll * prefZero * suffZero);
                prefOne++; // number of one before this index
                suffOne--; // number of one after this index
            }else{ // count 101
                ans += (1ll * prefOne * suffOne);
                prefZero++;
                suffZero--;
            }
        }
        return ans;
    }
};
/*
Only two possible sequence 010 , 101
Count using suffix and prefix count of 1 and 0
*/