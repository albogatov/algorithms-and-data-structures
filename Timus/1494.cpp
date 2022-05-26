#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    
    int pulled[n];
    
    vector<int> rolled;
    
    for (int i = 0; i < n; i++) {
        cin >> pulled[i];
    }
    
    int max_pulled = 0;
    
    for (int i = 0; i < n; i++) {
        if (pulled[i] > max_pulled) {
            for (int j = max_pulled + 1; j < pulled[i]; j++)
                rolled.push_back(j);
            max_pulled = pulled[i];
        } else {
            if (pulled[i] == rolled.back()) {
                rolled.pop_back();
                continue;
            }
                
            else {
                cout << "Cheater" << endl;
                return 0;
            }
        }
    }

    cout << "Not a proof" << endl;

    return 0;
}
