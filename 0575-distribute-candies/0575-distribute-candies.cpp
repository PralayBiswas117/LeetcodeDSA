class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int ans=0;
        std::unordered_set<int> seen;
        seen.reserve(candyType.size()/2);
        for(int candy:candyType){
            if(!seen.contains(candy)){
                ans++;
                if(ans==candyType.size()/2){return ans;}
                seen.insert(candy);
            }
        }
        return ans;
    }
};