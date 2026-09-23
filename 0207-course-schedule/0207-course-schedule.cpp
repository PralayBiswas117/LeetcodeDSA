class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>adj[n];

        vector<int>id(n,0);

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            id[u]++;
        }

        queue<int>q;

        for(int i=0;i<id.size();i++){
            if(id[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()){

            int node = q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[node].size();i++){
                id[adj[node][i]]--;
                if(id[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }

        if(count != numCourses) return false;

        return true;
    }
};