#include <bits/stdc++.h>

using namespace std;


int main() {
    map<int, int> cartas;
    for (int i=0; i<3; i++) {
        int carta;
        cin >> carta;
        if (cartas.find(carta) == cartas.end()) cartas[carta] = 0;
        cartas[carta]++;
    }
    for (auto carta : cartas) {
        if (carta.second != 1) continue;
        cout << carta.first << endl;
    }
}
