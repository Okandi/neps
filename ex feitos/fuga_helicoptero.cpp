#include <bits/stdc++.h>

using namespace std;


int main() {
    int helicoptero, policial, fugitivo, direcao;
    cin >> helicoptero >> policial >> fugitivo >> direcao;
    int certo;
    if (
        ((helicoptero < fugitivo) && (fugitivo < policial))
        || ((fugitivo < policial) && (policial < helicoptero))
        || ((policial < helicoptero) && (helicoptero < fugitivo))
    ) certo = -1;
    else certo = 1;

    if (certo == direcao) cout << "S" << endl;
    else cout << "N" << endl;
}
