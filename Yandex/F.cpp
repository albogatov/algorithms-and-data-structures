#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string current;
    
    vector<string> number;
    
    while (cin >> current) {
        if (number.empty())
            number.push_back(current);
        else {
            for (int i = number.size() - 1; i >= 0; i--) {
                if (number[i] + current > current + number[i]) {
                    number.insert(number.begin() + i + 1, current);
                    break;
                }
                if (i == 0) {
                    number.insert(number.begin(), current);
                }
            }
        }
    }
    
    for (int i = 0; i < number.size(); i++) {
        cout << number[i];
    }
    return 0;
}