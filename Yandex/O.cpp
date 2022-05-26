#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
    public:
        int color;
        int idx;
        Node() {
            this->color = 0;
        }
};


bool BFS_bipartite(vector<vector<int>> graph, int s) {
    vector<Node> visited(graph.size(), *(new Node()));
    visited[s].idx = 1;
    if (visited[s].color == 0)
        visited[s].color = 1;
    queue<int> ord;
    ord.push(s);
    while(!ord.empty()) {
        int current = ord.front();
        ord.pop();
        for (int i = 0; i < graph[current].size(); i++) {
            int v = graph[current][i];
            if (visited[v].color == 0) {
                visited[v].color = -visited[current].color;
                ord.push(v);
            }
            if (visited[v].color == visited[current].color)
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<int>> cheat_graph;
    cheat_graph.resize(n);
    vector<Node> vis(n, *(new Node()));
    
    for (int i = 0; i < m; i++) {
        int lk1;
        int lk2;
        cin >> lk1 >> lk2;
        --lk1;
        --lk2;
        cheat_graph[lk1].push_back(lk2);
		cheat_graph[lk2].push_back(lk1);
    }
    
    for (int i = 0; i < n; i++) {
        if (!BFS_bipartite(cheat_graph, i)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}
