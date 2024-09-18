#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtd;
    cin >> qtd;

    int campo[qtd+2];
    campo[0] = 0;
    for (int i=1; i<=qtd; i++) cin >> campo[i];
    campo[qtd+1] = 0;

    for (int i=1; i<=qtd; i++) {
        cout << campo[i-1] + campo[i] + campo[i+1] << endl;
    }
}
