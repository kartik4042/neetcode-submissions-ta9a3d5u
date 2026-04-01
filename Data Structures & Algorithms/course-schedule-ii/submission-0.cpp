class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
            vector<int> indegree(numCourses, 0);
            vector<vector<int>> graph(numCourses);

            for(auto &pre : prerequisites)
            {
                int next = pre[0];
                int prev = pre[1];
                graph[prev].push_back(next);
                indegree[next]++;
            }

            queue<int> q;
            for(int i = 0; i < numCourses; i++)
            {
                if(indegree[i] == 0)
                    q.push(i);
            }

            vector<int> order;
            int count = 0;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                order.push_back(u);
                count++;

                for(int v : graph[u])
                {
                    indegree[v]--;
                    if(indegree[v] == 0)
                        q.push(v);
                }
            }

            if(count != numCourses) return {};
            return order;
    }
};
