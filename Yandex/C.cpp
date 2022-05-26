#include <fstream>
#include <vector> 
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main () {
	
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	//vector<string> variables = vector<string>();
	vector<vector<string>> scopeVariables = vector<vector<string>>();
	map <string, vector<int>> storage = map<string, vector<int>>();
	
	string current;

    scopeVariables.push_back(vector<string>());
	while (true) {
	    fin >> current;
    	if(fin.eof())
        	break;
    	if (current == "{") {
        	    scopeVariables.push_back(vector<string>());
        } else if (current == "}") {
        	for (auto &key : scopeVariables.back()) {
        	    storage[key].pop_back();
        	}
        	scopeVariables.pop_back();
        } else {
        	int signPos = current.find("=");
        	string var1 = current.substr(0, signPos);
        	string var2 = current.substr(signPos+1);
        	if(var2.find_first_of("0123456789") != string::npos) {
        	    if(storage.find(var1) == storage.end()) {
        	        storage.insert(pair<string,vector<int>>(var1, vector<int>()));
        	    }
            	scopeVariables.back().push_back(var1);
            	storage[var1].push_back(stoi(var2));
            } else {
                 if(storage.find(var1) == storage.end()) {
        	        storage.insert(pair<string,vector<int>>(var1, vector<int>()));
        	        storage[var1].push_back(0);
        	    }
        	     if(storage.find(var2) == storage.end()) {
        	        storage.insert(pair<string,vector<int>>(var2, vector<int>()));
        	        storage[var2].push_back(0);
        	    }
                scopeVariables.back().push_back(var1);
            	storage[var1].push_back(storage[var2].back());
            	fout << storage[var2].back() << endl;
            	
            }
            
        }
	} 
	
	return 0;
}