class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});

        while(!q.empty())
        {
            auto [node, price, stops] = q.front();
            q.pop();

            if(stops > k) continue;
            
            for(auto &it : adj[node])
            {
                int next = it.first;
                int cost = it.second;

                int newCost = cost + price;
                if(newCost < distance[next])
                {
                    distance[next] = newCost;
                    q.push({next, newCost, stops + 1});
                }
            }
        }    
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
