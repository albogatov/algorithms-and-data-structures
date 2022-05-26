#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int bucket[n];
    
    for (int i = 0; i < n; i++) {
        cin >> bucket[i];
    }
    
    int sum = 0;
    
    int discount = n/k;
    
    for (int i = 1; i < n; i++) {
            int value = bucket[i];
            int j = i;
    
            while (j > 0 && bucket[j - 1] < value) {
                bucket[j] = bucket[j - 1];
                j--;
            }
    
            bucket[j] = value;
    }
    
    for (int i = 0; i < n; i++) {
        if ((i+1)%k != 0)
            sum += bucket[i];
    }
    
    cout << sum << endl;
    
    return 0;
}