class Solution {
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(grid[r][c] == '1')
                {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }    
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0')
            return;

        grid[row][col] = '0';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

    void bfs(vector<vector<char>>& grid, int row, int col)
    {
        queue<pair<int,int>> q;
        grid[row][col] = '0';
        q.push({row, col});

        while(!q.empty())
        {
            auto node = q.front(); q.pop();
            int r = node.first, c = node.second;

            for(int i = 0; i < 4; i++)
            {
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid.size() && grid[nr][nc] == '1')
                {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
