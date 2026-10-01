class Solution {
public:
    vector<int> num;
    long long ans;
    vector<vector<vector<int>>> dp;
    long long funct(int pos,int tight,int cnt_of_one){
        if(pos==num.size()) return cnt_of_one;
        if(dp[pos][tight][cnt_of_one]!=-1){
            return dp[pos][tight][cnt_of_one];
        }
        long long count = 0;
        if(tight==1){
            int bounded = num[pos];
            for(int i=0;i<=bounded;i++){   
                int isOne = (i==1);
                if(i==bounded){
                    count+=funct(pos+1,1,cnt_of_one+isOne);    
                }else{
                    count+=funct(pos+1,0,cnt_of_one+isOne);
                }
            }
        }else{
            for(int i=0;i<=9;i++){
                int isOne = (i==1);
                count+=funct(pos+1,0,cnt_of_one+isOne);
            }
        }
        return dp[pos][tight][cnt_of_one] = count;
    }
    int countDigitOne(int n) {  
        num.clear();
        int temp = n;
        ans = 0;
        if(n == 0) return 0;
        while(temp>0){
            num.push_back(temp%10);
            temp/=10;
        }
        reverse(num.begin(),num.end());
        dp.resize(num.size(), vector<vector<int>>(2, vector<int>(10, -1)));
        long long totalOne = funct(0,1,0);
        return totalOne;
    }
};