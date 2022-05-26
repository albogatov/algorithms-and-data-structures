#include <iostream>

using namespace std;

int main()
{
    int n, k;
    
    cin >> n >> k;
    
    int places[n];
    
    for (int i = 0; i < n; i++)
        cin >> places[i];
    
    int closest = 0;
    
    int furthest = places[n-1] - places[0];
    
    while (furthest > closest) {
        int middle = (closest + furthest) / 2;
        int current_cow = places[0];
        int counter = 1;
        for (int i = 0; i < n; i++) {
            if (places[i] - current_cow > middle) {
                current_cow = places[i];
                counter++;
            }
        }
        if (counter >= k) {
            closest = middle + 1;
        } else furthest = middle;
    }
    cout << closest;
    return 0;
}
