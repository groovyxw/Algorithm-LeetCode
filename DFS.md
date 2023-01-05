# DFS

python template:

def dfs(curr):
  visited.add(curr)   （树不用visited, we never visit same node in a tree）
  for next in neighbors(curr):
    if next not in visited:
      dfs(next)
      
0261. Graph Valid Tree

1. check for cycle
2. fully connected
Both can be done by DFS.
 
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (auto e : edges) {
            neighbors[e.first].push_back(e.second);
            neighbors[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        if (hasCycle(neighbors, 0, -1, visited))
            return false;
        for (bool v : visited)
            if (!v) return false; 
        return true;
    } 
private:
    bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& visited) {
        if (visited[kid]) return true;
        visited[kid] = true;
        for (auto neigh : neighbors[kid])
            if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
                return true;
        return false;
    }
};
  
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto x: edges){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }
        vector<int>visited(n);
        if(findCircle(graph, visited, -1, 0)) return false;
        for(auto x: visited) if(!x) return false;
        return true;
    }
    
    bool findCircle(vector<vector<int>>& graph, vector<int>& visited, int from, int node){
        if(visited[node]) return true;
        visited[node] = 1;
        bool circle = false;
        for(auto x: graph[node])
            if(x != from){
                circle |= findCircle(graph, visited, node, x);
                if(circle) return true;
            }
        return false;
    }
};
  
  
  
  // For a graph to be a tree:
//      1. Graph must be fully connected. => Use UF to find it.
//      2. Graph must not have any cycles. => If edges >= n, then there would be cycles.

class DSU {
    public:
    vector<int> parent, rank;
    int count;
    
    DSU(int n){
        count = n;
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py){
            if(rank[px] > rank[py])
                parent[py] = px;
            else if(rank[px] < rank[py])
                parent[px] = py;
            else {
                parent[py] = px;
                rank[px]++;
            }
            count--;
        }
    }
    int getCount(){
        return count;
    }
    
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& e) {
        if(e.size() >= n)
            return false;
        DSU uf(n);
        for(auto E: e){
            uf.Union(E[0], E[1]);
        }
        if(uf.getCount() == 1)
            return true;
        else
            return false;
    }
};

  0133. Clone Graph
  class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
        Node* cloneNode = new Node(node->val);
        // 哈希表存储
        visited[node] = cloneNode;

        // 遍历该节点的邻居并更新克隆节点的邻居列表
        for (auto& neighbor: node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }

        unordered_map<Node*, Node*> visited;

        // 将题目给定的节点添加到队列
        queue<Node*> Q;
        Q.push(node);
        // 克隆第一个节点并存储到哈希表中
        visited[node] = new Node(node->val);

        // 广度优先搜索
        while (!Q.empty()) {
            // 取出队列的头节点
            auto n = Q.front();
            Q.pop();
            // 遍历该节点的邻居
            for (auto& neighbor: n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // 如果没有被访问过，就克隆并存储在哈希表中
                    visited[neighbor] = new Node(neighbor->val);
                    // 将邻居节点加入队列中
                    Q.push(neighbor);
                }
                // 更新当前节点的邻居列表
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};
