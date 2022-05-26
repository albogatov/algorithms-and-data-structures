#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int x[n];
    int y[n];
    long long distance_walked = 0;
    
    for (long long  i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    sort(x, x+n);
    sort(y, y+n);
    
    for (long long  i = 1; i < n; i++) {
        distance_walked += abs(x[i] - x[i-1] + y[i] - y[i-1]) * i * (n-i);
    }
    
    cout << (distance_walked * 2)/(n*(n-1)) << endl;
    
    return 0;
}