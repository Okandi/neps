#include <bits/stdc++.h>

using namespace std;


int main() { // O(raiz(n))
    long long numero;
    cin >> numero;

    bool primo = numero != 1;
    for (long long i=2; i<=numero/i; i+=2) {
        if (numero%i == 0) {
            primo = false;
            break;
        }
        if (i == 2) i++;
    }

    if (primo) cout << "S" << endl;
    else cout << "N" << endl;
}
