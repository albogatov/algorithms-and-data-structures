#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
    int array[n];
    int sameFlowersAmount = 1;
    int longestStart = 0;
    int longestEnd = 0;
    int currentStart = 0;
    int currentEnd = 0;
    
    for (int i = 0; i < n; i++) {
    	cin >> array[i];
    }

    for (int i = 1; i < n; i++) {
    	if (array[i] == array[i-1]) {
        	sameFlowersAmount++;
            if (sameFlowersAmount >= 3) {
            	if (currentEnd - currentStart > longestEnd - longestStart) {
                	longestStart = currentStart;
                    longestEnd = currentEnd;
                }
                currentStart = i - 1;
                sameFlowersAmount--;
            }
        } else sameFlowersAmount = 1;
        currentEnd = i;
        if (i == n - 1 && (currentEnd - currentStart > longestEnd - longestStart)) {
             longestStart = currentStart;
             longestEnd = currentEnd;
        }
    }

    cout << longestStart + 1 << " " << longestEnd + 1; 
    return 0;
    
}