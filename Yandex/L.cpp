#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int n,k;
    
    cin >> n >> k;
    
    vector<int> nums;
    
    for (int i = 0 ; i < n; i++) {
        int current; 
        cin >> current;
        nums.push_back(current);
    }
    
    int min_idx;
    int min = 100001;
    
    deque<int> window;
    vector<int> solution;
    
    for (int i = 0; i < n; i++) {
        if (window.size() > 0 && window.front() <= i - k)
            window.pop_front();
        while (window.size() > 0 && nums.at(window.back()) >= nums.at(i))
            window.pop_back();
        window.push_back(i);
        if (i >= k - 1) {
            solution.push_back(nums.at(window.front()));
        }
    }
    
    for (int i = 0; i < solution.size(); i++)
        cout << solution.at(i) << " ";
    
    return 0;
}