#include <iostream>
#include <map>

using namespace std;

int main()
{
    string current;
    
    cin >> current;
    
    int weight[26];
    
    char alphabet[26];
    
    char base = 'a';
    
    int counter[26];
    
    string result = "";
    
    map<char, int> postSortIdxs;
    
    for (int i = 0; i < 26; i++) {
        cin >> weight[i];
        alphabet[i] = base + i;
        counter[i] = 0;
    }
    
    for (int i = 1; i < 26; i++) {
            int value = weight[i];
            int alpha_value = alphabet[i];
            int j = i;
            while (j > 0 && weight[j - 1] < value) {
                weight[j] = weight[j - 1];
                alphabet[j] = alphabet[j-1];
                j--;
            }
            weight[j] = value;
            alphabet[j] = alpha_value;
    }
    
    for (int i = 0; i < 26; i++) {
        postSortIdxs[alphabet[i]] = i;
    }
    
    for (int i = 0; i < current.size(); i++) {
        counter[postSortIdxs[current[i]]]++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (counter[i] >= 2) {
           result += alphabet[i];
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (counter[i] == 1) 
            result += alphabet[i];
    }
    
    for (int i = 0; i < 26; i++) {
        while (counter[i] > 2) {
                result += alphabet[i];
                counter[i]--;
        }
    }
    
    for (int i = 25; i >= 0; i--) {
        if (counter[i] >= 2) 
            result += alphabet[i];
    }
    

    cout << result << endl;
    
    return 0;
}