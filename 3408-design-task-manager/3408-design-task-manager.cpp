class TaskManager {
    priority_queue<vector<int>> pq;
    unordered_map<int,vector<int>> task;
    int ver = 0;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t:tasks){
            pq.push({t[2], t[1], t[0], ver});
            task[t[1]] = {t[2], t[0], ver++};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId, userId, ver});
        task[taskId] = {priority, userId, ver++};
    }
    
    void edit(int taskId, int newPriority) {
        task[taskId][0] = newPriority;
        task[taskId][2] = ver; 
        pq.push({newPriority, taskId, task[taskId][1], ver++});
    }
    
    void rmv(int taskId) {
        task.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty() && (!task.count(pq.top()[1]) || pq.top()[3] != task[pq.top()[1]][2] || pq.top()[2] != task[pq.top()[1]][1] || pq.top()[0] != task[pq.top()[1]][0])){
            pq.pop();
        }
        if(pq.empty()) return -1;
        int user = pq.top()[2]; pq.pop();
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */