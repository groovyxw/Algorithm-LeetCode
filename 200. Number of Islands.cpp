class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[row][col] = '0';
        if(row-1>=0 && grid[row-1][col] == '1') dfs(row-1,col,grid);
        if(row+1<nr && grid[row+1][col] == '1') dfs(row+1,col,grid);
        if(col-1>=0 && grid[row][col-1] == '1') dfs(row,col-1,grid);
        if(col+1<nc && grid[row][col+1] == '1') dfs(row,col+1,grid);
        return;
    }
    void bfs(int r, int c, vector<vector<char>> &grid) {
        int gr = grid.size();
        int gc = grid[0].size();

        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.emplace(r,c);
        grid[r][c] = '0';

        while (!q.empty()) {
            auto rc = q.front();
            q.pop();

            int cur_r = rc.first;
            int cur_c = rc.second;

            for (auto delta : directions) {
                int new_r = cur_r + delta.first;
                int new_c = cur_c + delta.second;

                if(new_r < 0 || new_r >= gr || new_c < 0 || new_c >= gc || grid[new_r][new_c] == '0') continue;
                grid[new_r][new_c] = '0';
                q.emplace(new_r, new_c);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int gr = grid.size();
        int gc = grid[0].size();

        int numIslands = 0;
        for (auto r = 0; r < gr; r++) {
            for (auto c = 0; c < gc; c++) {
                if (grid[r][c] == '1') {
                    numIslands++;
                    //dfs(r, c, grid);
                    bfs(r, c, grid);
                }

        // //DFS
        // int r = grid.size();
        // if (0 == r) {
        //     return 0;
        // }
        // int c = grid[0].size();

        // int numIslands = 0;
        // for (auto i = 0; i < r; i++) {
        //     for (auto j = 0; j < c; j++) {
        //         if (grid[i][j] == '0') continue;
        //         numIslands++;
        //         //DFS
        //         dfs(i,j, grid);


                // // BFS
                // grid[i][j] = '0';
                // queue<pair<int,int>> q;
                // q.emplace(i,j);
                // while (!q.empty()) {
                //     auto rc = q.front();
                //     q.pop();
                //     int row = rc.first;
                //     int col = rc.second;
                //     if (row - 1 >= 0 && grid[row-1][col] == '1') {
                //         q.emplace(row-1, col);
                //         grid[row-1][col] = '0';
                //     }
                //     if (row + 1 < r && grid[row + 1][col] == '1') {
                //         q.emplace(row+1, col);
                //         grid[row+1][col] = '0';
                //     }
                //     if (col - 1 >= 0 && grid[row][col-1] == '1') {
                //         q.emplace(row, col-1);
                //         grid[row][col-1] = '0';
                //     }
                //     if (col + 1 < c && grid[row][col+1] == '1') {
                //         q.emplace(row, col+1);
                //         grid[row][col+1] = '0';
                //     }
                // }
            }
        }
        return numIslands;
    }
};



// Python Union Find
#UnionFind
class UnionFind:
    
    def __init__(self, grid):
        self.father = collections.defaultdict(int)
        self.cnt = 0    # total # of isolated components in the graph
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    self.father[(i, j)] = (i, j)
                    self.cnt += 1
    
    def find(self, x):
        if self.father[x] == x:
            return x
        self.father[x] = self.find(self.father[x])
        return self.father[x]
        
    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.father[root_a] = root_b
            self.cnt -= 1     

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0
        
        uf = UnionFind(grid)        # instantiate a UnionFind object
        
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    for delta_i, delta_j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                        next_i, next_j = i + delta_i, j + delta_j
                        if 0 <= next_i < m and 0 <= next_j < n and grid[next_i][next_j] == "1":
                            uf.connect((i, j), (next_i, next_j))   
                            # union method include: 1. find the root of a and b; 2. connect a and b; 3. reduce cnt
        return uf.cnt
        
