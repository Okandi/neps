#include <bits/stdc++.h>

using namespace std;


int main() {
    int vezes;
    cin >> vezes;

    int lancamentos[12];
    for (int i=0; i<12; i++) lancamentos[i] = 0;
    for (int i=0; i<vezes; i++) {
        int resultado;
        cin >> resultado;
        lancamentos[resultado-1]++;
    }

    int* maxValue = max_element(begin(lancamentos), end(lancamentos));
    for (int i=0; i<12; i++) {
        if (lancamentos[i] == *maxValue) cout << i+1 << " ";
    }
    cout << endl;
}
