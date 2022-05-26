#include <iostream>
 
using namespace std;
 
int main()
{   
    int n;
    cin >> n;
    int sequence[n];
    int currentSum = 0;
    int maxSum = currentSum;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    for (int i = 0; i < n; i++) {
        currentSum += sequence[i];
        if (currentSum <= 0)
            currentSum = 0;
        else if (currentSum > maxSum) maxSum = currentSum;
    }
    cout << maxSum << endl;
    return 0;
}