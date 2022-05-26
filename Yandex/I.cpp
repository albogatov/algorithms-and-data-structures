#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

// map<int, int> counter_entries;
// map<int, int> counter_positions;

// bool compare_cars(int i, int j) {
//   list<int> copy = on_floor;
//   return counter_entries[i] < counter_entries[j]; 
// }

int main()
{
    
    int n, k, p;
    
    int ops = 0;
    
    cin >> n >> k >> p;
    
    int cars_order[p];
    
    unordered_set<int> on_floor;
    
    list<int> entry_positions[n];
    
    priority_queue<pair<int, int>> order;
    
    for (int i = 0; i < p; i++) {
        cin >> cars_order[i];
        entry_positions[--cars_order[i]].push_back(i);
    }
    
    for (int i = 0; i < p; i++) {
        int current = cars_order[i];
        entry_positions[current].pop_front();
        if(on_floor.find(current) == on_floor.end()) {
            if (on_floor.size() + 1 > k) {
                on_floor.erase(order.top().second);
                order.pop();
            }
            on_floor.insert(current);
            ops++;
        }
        if (!entry_positions[current].empty())
            order.push({entry_positions[current].front(), current});    
        else order.push({500001,current});
    }
    
    cout << ops;
    
    return 0;
}
