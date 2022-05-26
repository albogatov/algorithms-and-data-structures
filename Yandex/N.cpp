#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        string color;
        Node() {
            this->color = "WHITE";
        }
};


void DFS_visit(vector<vector<int>>& graph, int s, vector<Node>& visit_map, int& t) {
    visit_map[s].color = "GRAY";
    for (int i = 0; i < graph[s].size(); ++i) {
        int v = graph[s][i];
        if (visit_map[v].color == "WHITE") {
            DFS_visit(graph, v, visit_map, t);
        } else if (visit_map[v].color == "GRAY") t++;
    }
    visit_map[s].color = "BLACK";
}

void DFS(vector<vector<int>>& graph, vector<Node>& visit_map, int& counter) {
    for (int i = 0; i < graph.size(); ++i) {
        if (visit_map[i].color == "WHITE")
            DFS_visit(graph, i, visit_map, counter);
    }
}


int main() {
    
    int n;
    int result = 0;
    
    cin >> n;
    
    vector<vector<int>> pig_graph;
    pig_graph.resize(n);
    vector<Node> vis(n, *(new Node()));
    
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        pig_graph[i].push_back(--key);
    }
     
    DFS(pig_graph, vis, result);
    
    cout << result << endl;
    return 0;
}
