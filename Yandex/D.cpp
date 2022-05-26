#include <iostream>

using namespace std;

int main() {

	int a;
	int b;
	int c;
	int d;
	int k;
	
	cin >> a >> b >> c >> d >> k;

	int left = a;
	int infCycleCheck = 0;

	for (int i = 0; i < k; i++) {
    	left = left * b - c;
    	if (left <= 0) {
        	left = 0;
        	break;
        }
   		if (left >= d) {
        	left = d;
    	}
    	if (left == infCycleCheck)
        	break;
    	infCycleCheck = left;
	}
	cout << left;

	return 0;
}