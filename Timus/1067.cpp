#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Directory {
    
    public: 
    
    map<string, Directory*> children;
    
    Directory() {
        
    }
    
    Directory* make_dir(string dir_name) {
        if (children.find(dir_name) == children.end()) {
            children[dir_name] = new Directory();
        }
        return children[dir_name];
    }
    
    void display_hierarchy(string indentation, bool is_root) {
        if(!is_root)
            indentation += " ";
        for (auto& child : children) {
            cout << indentation << child.first << endl;
            child.second->display_hierarchy(indentation, false);
        }
        
    }
    
};

int main()
{
    int n;
    
    cin >> n;
        
    Directory* root_dir = new Directory();
    char separator = '\\';
    Directory* current_dir;
    
    for (int i = 0; i < n; i++) {
        string current;
        vector<string> parsed_path;
        
        current_dir = root_dir;
        cin >> current;
        replace(current.begin(), current.end(), separator, ' ');
        stringstream ss(current);
        string tmp;
        while (ss >> tmp)
            parsed_path.push_back(tmp);
            
        for (string parsed_dir : parsed_path) {
            current_dir = current_dir->make_dir(parsed_dir);
        }
    }
    root_dir->display_hierarchy("", true);
    delete current_dir;
    delete root_dir;
    return 0;
}