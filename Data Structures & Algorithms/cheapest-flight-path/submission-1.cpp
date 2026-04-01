class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        queue<tuple<int,int,int>> q;
        q.push({src, 0, 0});

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        while(!q.empty())
        {
            auto [node, cost, stops] = q.front();
            q.pop();

            if(stops > k) continue;

            for(auto &it : adj[node])
            {
                int next = it.first;
                int price = it.second;

                int newCost = price + cost;
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
