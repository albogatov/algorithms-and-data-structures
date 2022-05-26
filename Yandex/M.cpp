#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x0, y0, xe, ye;
int mark = 0;
int maximum_dist = 2147483647;

class Block {
    public:
        int id;
        
        int x;
        int y;
        int weight;
        int mark;
        bool visited;
        
        Block (int id, int x, int y, int weight, bool visited) {
    		this->id = id;
    		this->x = x;
    		this->y = y;
    		this->weight = weight;
    		this->visited = visited;
    		this->mark = maximum_dist;
	    }
};


class compare
{
    public:
        bool operator()(Block* a,Block* b) {
            return a->mark < b->mark;
        }
};

vector<vector<Block*>> field(1000, vector<Block*>(1000, new Block(-1, -1, -1, -1, true)));

void path_by_dijkstra(int x, int y) {
    priority_queue<Block*, vector<Block*>, compare> ord;
    field[x][y]->mark = 0;
    ord.push(field[x][y]);
    while(!ord.empty()) {
        x = ord.top()->x;
        y = ord.top()->y;
        ord.pop();
        if (field[x][y]->visited)
            continue;
        field[x][y]->visited = 1;
        
        if (x > 0 && !field[x-1][y]->visited && field[x-1][y]->weight != -1) {
            if (field[x][y]->mark + field[x-1][y]->weight < field[x-1][y]->mark)
                field[x-1][y]->mark = abs(field[x][y]->mark) + field[x-1][y]->weight;
            if (field[x-1][y]->mark > 0)
                field[x-1][y]->mark = -field[x-1][y]->mark;
            ord.push(field[x-1][y]);
        }
        
        if (x < n-1 && !field[x+1][y]->visited && field[x+1][y]->weight != -1) {
            if (field[x][y]->mark + field[x+1][y]->weight < field[x+1][y]->mark)
                field[x+1][y]->mark = abs(field[x][y]->mark) + field[x+1][y]->weight;
            if (field[x+1][y]->mark > 0)
                field[x+1][y]->mark = -field[x+1][y]->mark;
            ord.push(field[x+1][y]);
        }
        
        if (y > 0 && !field[x][y-1]->visited && field[x][y-1]->weight != -1) {
            if (field[x][y]->mark + field[x][y-1]->weight < field[x][y-1]->mark)
                field[x][y-1]->mark = abs(field[x][y]->mark) + field[x][y-1]->weight;
            if (field[x][y-1]->mark > 0)
                field[x][y-1]->mark = -field[x][y-1]->mark;
            ord.push(field[x][y-1]);
        }
        
        if (y < m-1 && !field[x][y+1]->visited && field[x][y+1]->weight != -1) {
            if (field[x][y]->mark + field[x][y+1]->weight < field[x][y+1]->mark)
                field[x][y+1]->mark = abs(field[x][y]->mark) + field[x][y+1]->weight;
            if (field[x][y+1]->mark > 0)
                field[x][y+1]->mark = -field[x][y+1]->mark;
            ord.push(field[x][y+1]);
        }
    }
}

void trace_by_dijkstra(int x, int y)
{
    if (!field[x][y]->mark)
        return;
    mark = field[x][y]->mark;
    char direction;
    if (x > 0 && mark > field[x-1][y]->mark) {
        direction = 'S';
        mark = field[x-1][y]->mark;
    }
    if (x < n-1 && mark > field[x+1][y]->mark) {
        direction = 'N';
        mark = field[x+1][y]->mark;
    }
    if (y > 0 && mark > field[x][y-1]->mark) {
        direction = 'E';
        mark = field[x][y-1]->mark;
    }
    if (y < m-1 && mark > field[x][y+1]->mark) {
        direction = 'W';
        mark = field[x][y+1]->mark;
    }
    if (direction == 'S') {
        trace_by_dijkstra(x - 1, y);
    } else if (direction == 'N') {
        trace_by_dijkstra(x + 1, y);
    } else if (direction == 'E') {
        trace_by_dijkstra(x, y - 1);
    } else if (direction == 'W') {
        trace_by_dijkstra(x, y + 1);
    }
    cout << direction;
}

int get_weight(char terrain) {
    switch (terrain) {
        case '.':
            return 1;
        case 'W':
            return 2;
        default:
            return -1;
    }
}

int main() {

    cin >> n >> m >> x0 >> y0 >> xe >> ye;

    int counter = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char terrain;
            cin >> terrain;
            int weight = get_weight(terrain);
            field[i][j] = new Block(counter, i, j, weight, false);
            counter++;
        }
    }
    x0--;
    y0--;
    xe--;
    ye--;
    
    path_by_dijkstra(x0, y0);
    
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j]->mark < 0)
                field[i][j]->mark = -field[i][j]->mark;
        }
    }
    
    if (field[xe][ye]->mark == maximum_dist) {
        cout << -1;
    } else {
        cout << field[xe][ye]->mark << endl;
        trace_by_dijkstra(xe, ye);
    }

    cout << endl;
    return 0;
}
