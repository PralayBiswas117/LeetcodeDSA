class Solution {
public:
    int find(int x , vector<int>&par){
        if(x == par[x]){
            return x;
        }
        return par[x] = find(par[x] , par);
    }
    void Union(int x , int y , vector<int>&par , vector<int>&rank){
        int x_par = find(x , par);
        int y_par = find(y, par);
        if(x_par == y_par)return ;
        if(rank[x_par] < rank[y_par]){
            par[x_par] = y_par;
        }
        else if(rank[x_par] > rank[y_par]){
            par[y_par] = x_par;
        }
        else{
            par[y_par] = x_par;
            rank[x_par]++;
        }
    }
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        // we can swap all the el with common factor 
        // jin jinko we can swap un sabka par ek hi ho jayega 
        // then check the par of sorted array and cur array if same then ok
        // can do nroot n
        int mx = LLONG_MIN;
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n; i++){
            mp[nums[i]]++;
        }
        for(int i = 0 ; i <n ; i++){
            mx = max(mx , nums[i]);
        }
        vector<int>par(mx + 1);
        vector<int>rank(mx + 1 , 0);

        for(int i = 0 ; i<=mx ;i++){
            par[i] = i;
        }
        for(int i = 2 ; i <= mx ; i++){
            
            for(int j = i ; j <= mx ; j += i){
                if(mp.count(j)){

                if(find(i , par) != find(j , par)){
                    Union(i , j , par, rank);
                }
                }
            }
        }

        vector<int>tmp = nums;
        sort(tmp.begin() , tmp.end());
        // for(int i = 0 ; i < n ; i++){
        //     cout<<tmp[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0 ; i <= mx ; i++){
        //     cout<<par[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 0 ; i < n ; i++){
            if(find(tmp[i] , par) != find(nums[i] , par)){
                return false;
            }
        }
        return true;
    }
};