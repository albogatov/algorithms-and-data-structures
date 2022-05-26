#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    deque<string> goblins_one;
    deque<string> goblins_two;
    
    int n;
    
    cin >> n;
    
    vector<string> solution;
    
    for (int i = 0; i < n; i++) {
        string current;
        cin >> current;
        if (current == "+") {
            cin >> current;
            goblins_two.push_front(current);   
        }
        else if (current == "*") {
            cin >> current;
            goblins_two.push_back(current);
        } else {
            solution.push_back(goblins_one.back());
            goblins_one.pop_back();
        }
        
        if (goblins_one.size() < goblins_two.size()) {
            goblins_one.push_front(goblins_two.back());
            goblins_two.pop_back();
        }
    }
    
    for (int i = 0 ; i < solution.size(); i++)
        cout << solution.at(i) << endl;
    
    return 0;
}