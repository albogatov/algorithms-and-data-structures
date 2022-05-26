#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#define PI 3.1415926535897932384626433832795028841971693993751058

using namespace std;


void merge(double * a, double * aux, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    // for (int k = l; k <= r; ++k) {
    //     aux[k] = a[k];
        
    // }
    for (int k = l; k <= r; ++k) {
        if (i > m) { 
            a[k] = aux[j++]; 
            continue; 
        }
        if (j > r) { 
            a[k] = aux[i++];
            continue; 
        }
        if (aux[j] < aux[i]) { 
            a[k] = aux[j++];
        }
        else {
            a[k] = aux[i++];
        }
    }
}


void merge_sort(double * a, double * aux, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(aux, a, l, m);
        merge_sort(aux, a, m + 1, r);
        merge(a, aux, l, m, r);
    }
}

void _sort(double* a, int N) {
    double* aux = new double[N];
    for (int k = 0; k < N; ++k)  {
        aux[k] = a[k];
    }
    merge_sort(a, aux, 0, N-1);
    delete[] aux;
}

int main()
{
    int n;
    cin >> n;
    int dots[n][2];
    int min_x = 1000001;
    int min_y = 1000001;
    int min_dot_idx = -1;
    int min_dot[1][2];
    double atans[n];
    double atans_copy[n];

    for (int i = 0; i< n; i++) {
        cin >> dots[i][0] >> dots[i][1];
    }
    
    for (int i = 0; i < n; i++) {
        if (dots[i][1] < min_y || dots[i][1] == min_y && dots[i][0] < min_x) {
            min_dot_idx = i;
            min_x = dots[i][0];
            min_y = dots[i][1];
        }
    }
    
    min_dot[0][0] = dots[min_dot_idx][0];
    min_dot[0][1] = dots[min_dot_idx][1];
    
    
    for (int i = 0; i < n; i++) {
        double current_atan;
        if (dots[i][0] == min_dot[0][0]) 
            current_atan = PI / 2; 
        else if (dots[i][1] == min_dot[0][1]) 
            current_atan = 0;

        else current_atan = atan((double) (dots[i][1] - min_dot[0][1]) / (double) (dots[i][0] - min_dot[0][0]));
        if (current_atan < 0) current_atan += 2 * PI;
        atans[i] = current_atan;
        atans_copy[i]=current_atan;
    }
    
    swap(atans[n-1], atans[min_dot_idx]);

    
    _sort(atans, n-1);


    cout << min_dot_idx + 1 << " ";
    for(int i = 0; i < n; i++) {
        if (atans_copy[i] == atans[(n-1)/2]) {
            cout << i+1 << endl;
            break;
        }
    }
    
    return 0;
}