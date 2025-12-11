class Solution {
public:
    int cnt = 0;
    bool vis[105][105];
    vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};

    bool valid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void dfs(int si,int sj, vector<vector<int>>& grid, int n, int m){
        vis[si][sj] = true;

        for(int k=0;k<4;k++){
            int ci = si + d[k].first;
            int cj = sj + d[k].second;

            // If outside grid → contributes to perimeter
            if(!valid(ci, cj, n, m)) {
                cnt++;
            }
            // If water → contributes to perimeter
            else if(grid[ci][cj] == 0){
                cnt++;
            }
            // If unvisited land → DFS
            else if(!vis[ci][cj] && grid[ci][cj] == 1){
                dfs(ci, cj, grid, n, m);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        memset(vis, false, sizeof(vis));
        cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, n, m);
                    return cnt;  // Only one island → return immediately
                }
            }
        }

        return 0;
    }
};
