#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int min_dist = -2147483647;

class Wire {
    public:
        int from, to, benefit;
        
        Wire(int from, int to, int benefit) {
            this->from = from;
            this->to = to;
            this->benefit = benefit;
        }
        
        Wire() {
            
        }
};

int main()
{
    int n,m,s,f;

    cin >> n >> m;
    
    Wire* wire_array[m];
    
    for (int i = 0; i < m; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            wire_array[i] = new Wire(a,b,c);
    }
    
    cin >> s >> f;
    
    vector<int> path_dijkstra(n+1, min_dist);
    
    path_dijkstra[s] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (path_dijkstra[wire_array[j]->from] != min_dist && path_dijkstra[wire_array[j]->to] < wire_array[j]->benefit + path_dijkstra[wire_array[j]->from]) {
                path_dijkstra[wire_array[j]->to] = path_dijkstra[wire_array[j]->from] + wire_array[j]->benefit;     
            }
        }
    }
    
    if (path_dijkstra[f] > min_dist)
        cout << path_dijkstra[f] << endl;
    else cout << "No solution";
    
    return 0;
}