class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and calculate indegree
        for (auto& edge : prerequisites) {

            int course = edge[0];
            int prerequisite = edge[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> que;

        // Add courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> answer(numCourses);
        int index = 0;

        // Kahn's Algorithm
        while (!que.empty()) {

            int curr = que.front();
            que.pop();

            answer[index++] = curr;

            // Process dependent courses
            for (int neighbor : graph[curr]) {

                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    que.push(neighbor);
                }
            }
        }

        // If not all courses were processed, a cycle exists.
        if (index != numCourses) {
            return {};
        }

        return answer;
    }
};