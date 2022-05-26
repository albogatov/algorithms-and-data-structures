#include <iostream>
 
using namespace std;
 
int main()
{   
    int t;
    int k;
    int n;
    int battles;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        battles = ((n-n/k)*(n-n%k*(n/k+1)) + n%k*(n/k+1)*(n-(n/k+1)))/2;
        cout << battles << endl;
    }
    return 0;
}