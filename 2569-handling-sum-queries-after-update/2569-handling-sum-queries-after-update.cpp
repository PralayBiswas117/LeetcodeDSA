class SegmentTree{
public:
    int n;
    long long total;
    vector<pair<long,long>> segTree1;
    vector<long long> segTree2;
    vector<int> lazyTree1;
    void buildSegTree1(vector<int>& nums1,int i,int l,int r){
        if(l == r){
            if(nums1[l] == 0) segTree1[i] = {1,0};
            else segTree1[i] = {0,1};
            return;
        }
        int mid = (l+r)/2;
        buildSegTree1(nums1,2*i+1,l,mid);
        buildSegTree1(nums1,2*i+2,mid+1,r);
        segTree1[i] = {segTree1[2*i+1].first+segTree1[2*i+2].first,segTree1[2*i+1].second+segTree1[2*i+2].second};
    }
    void updateSegTree1(int left,int right,int i,int l,int r){
        if(lazyTree1[i]!=0){
            swap(segTree1[i].first,segTree1[i].second);
            if(l!=r){
                lazyTree1[2*i+1] = (lazyTree1[2*i+1]+1)%2;
                lazyTree1[2*i+2] = (lazyTree1[2*i+2]+1)%2;
            }
            lazyTree1[i] = 0;
        }
        if(r<left || right < l) return;
        else if(left <= l && r<= right){
            swap(segTree1[i].first,segTree1[i].second);
            if(l!=r){
                lazyTree1[2*i+1] = (lazyTree1[2*i+1]+1)%2;
                lazyTree1[2*i+2] = (lazyTree1[2*i+2]+1)%2;
            }
            return;
        }
        else{
            int mid = (l+r)/2;
            updateSegTree1(left,right,2*i+1,l,mid);
            updateSegTree1(left,right,2*i+2,mid+1,r);
            segTree1[i] = {segTree1[2*i+1].first+segTree1[2*i+2].first,segTree1[2*i+1].second+segTree1[2*i+2].second};
        }
    }
    void updatetotal(int val){
        long long add = 0;
        add += (segTree1[0].second*val);
        total += add;
    }
    SegmentTree(vector<int>& nums1, vector<int>& nums2){
        n = nums1.size();
        segTree1.resize(4*n);
        segTree2.resize(4*n);
        lazyTree1.resize(4*n);
        buildSegTree1(nums1,0,0,n-1);
        for(auto&it : nums2) total+=it;
    }
    void query1(int left,int right){
        updateSegTree1(left,right,0,0,n-1);
    }
    void query2(int val){
        updatetotal(val);
    }
    long long query3(){
        return total;
    }
};
class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> ans;
        SegmentTree obj = SegmentTree(nums1,nums2);
        for(auto it : queries){
            if(it[0] == 1) obj.query1(it[1],it[2]);
            else if(it[0] == 2) obj.query2(it[1]);
            else{
                ans.push_back(obj.query3());
            }
        }
        return ans;
    }
};