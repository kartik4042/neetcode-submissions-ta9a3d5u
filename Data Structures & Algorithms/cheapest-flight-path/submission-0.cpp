class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for(auto &f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }    

        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});

        while(!q.empty())
        {
            auto[node, cost, stops] = q.front();
            q.pop();

            if(stops > k) continue;

            for(auto &neighbor : adj[node])
            {
                int next = neighbor.first;
                int price = neighbor.second;

                if(cost + price < distance[next])
                {
                    distance[next] = cost + price;
                    q.push({next, distance[next], stops + 1});
                }
            }
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
