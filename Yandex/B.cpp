#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main() {
	stack <pair<char, int>> zoo;
	int animals = 0;
	int traps = 0;
	string sequence;
	cin >> sequence;
	int n = sequence.size() / 2;
	int solution[n];
	for (char current : sequence) {
    	if (!zoo.empty() && tolower(current) == tolower(zoo.top().first) && ( isupper(current) && islower(zoo.top().first) || isupper(zoo.top().first) && islower(current))) {
            if (isupper(current))
            	solution[traps++] = zoo.top().second;
        	else solution[zoo.top().second] = animals++;
            zoo.pop();
        } else {
        	if (isupper(current))
            	zoo.push(pair<char,int>(current, traps++));
        	else zoo.push(pair<char,int>(current, animals++));
        } 
	}
	if (zoo.empty()) {
    	cout << "Possible" << endl;
    	for (int i = 0; i < n; i++)
        	cout << solution[i] + 1 << " ";
	} else cout << "Impossible" << endl;
	return 0 ;
}