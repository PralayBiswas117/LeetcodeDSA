class Solution {
public:
    int longestSubstring(string s, int k) {// TC : O((N+N)*26) = O(N) & SC : O(1)

        int n = s.size();//N
        int ans = 0;

        for(int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++){// TC : O(26) = O(1)
            vector<int>freq(26,0);// SC : O(26) = O(1)

            int i=0;
            int j=0;

            int unique = 0;
            int appearsAtLeastKtimes = 0;


            while(j<n){// TC : O(N)

                int index = s[j] - 'a';

                if(freq[index] == 0){
                    unique++;
                }

                freq[index]++;

                if(freq[index] == k){
                    appearsAtLeastKtimes++;
                }


                while(unique > uniqueTarget){// TC : O(N)

                    int leftIdx = s[i] - 'a';

                    if(freq[leftIdx] == k){
                        appearsAtLeastKtimes--;
                    }

                    freq[leftIdx]--;

                    if(freq[leftIdx] == 0){
                        unique--;
                    }

                    i++;
                }

                if(unique == uniqueTarget && unique == appearsAtLeastKtimes){
                    ans = max(ans,j-i+1);
                }

                j++;

            }
        }

        return ans;
    }
};