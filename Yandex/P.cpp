#include <iostream>
#include <vector>
using namespace std;

#define LIMIT 1000000000;

struct Node {
    int color;
};


void DFS_visit(bool direction, vector<vector<int>>& graph, int s, vector<Node>& visit_map, int& t, int& length) {
    visit_map[s].color = 1;
    t++;
    for (int i = 0; i < graph[s].size(); ++i) {
        int v;
        if (!direction)
            v = graph[s][i];
        else v = graph[i][s];
        if (visit_map[i].color == 0 && v <= length) {
            DFS_visit(direction, graph, i, visit_map, t, length);
        }
    }
}

bool DFS_is_connected_check(vector<vector<int>>& graph, int& n, int length) {
    int counter = 0;
    int counter_backwards = 0;
    vector<Node> vmap(n, {0});
    DFS_visit(false, graph, 0, vmap, counter, length);
    vector<Node> vmap_backwards(n, {0});
    if (counter == n) {
        DFS_visit(true, graph, 0, vmap_backwards, counter_backwards, length);
        return (counter == counter_backwards);
    }
    return false;
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int left = 0;
    int right = LIMIT;
    while (right > left) {
        int middle = (left + right) / 2;
        if (DFS_is_connected_check(graph, n, middle)) 
            right = middle;
        else left = middle + 1;
    }
    cout << right << endl;
    return 0;
}
