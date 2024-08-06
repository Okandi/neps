#include <bits/stdc++.h>

using namespace std;


int main() {
    int tamanhoBarra;
    cin >> tamanhoBarra;
    pair<int, int> adesivoA, adesivoB;
    cin >> adesivoA.first >> adesivoA.second;
    cin >> adesivoB.first >> adesivoB.second;
    bool possivel = !(((adesivoA.first <= tamanhoBarra/2) == (adesivoB.first <= tamanhoBarra/2)) && ((adesivoA.second <= tamanhoBarra/2) == (adesivoB.second <= tamanhoBarra/2)));
    if (possivel) cout << "S" << endl;
    else cout << "N" << endl;
}
