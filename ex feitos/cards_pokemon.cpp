#include <bits/stdc++.h>

using namespace std;


void montaDeck(set<int> &deck, int qtdCartas) {
    for (int i=0; i<qtdCartas; i++) {
        int carta;
        cin >> carta;
        deck.insert(carta);
    }
}


int main() {
    int qtdAlice, qtdBeatriz;
    cin >> qtdAlice >> qtdBeatriz;

    set<int> deckAlice, deckBeatriz;
    montaDeck(deckAlice, qtdAlice);
    montaDeck(deckBeatriz, qtdBeatriz);

    set<int> deckMisturado;
    deckMisturado.insert(deckAlice.begin(), deckAlice.end());
    deckMisturado.insert(deckBeatriz.begin(), deckBeatriz.end());

    for (auto carta : deckMisturado) {
        if (
            deckAlice.find(carta) != deckAlice.end()
            && deckBeatriz.find(carta) != deckBeatriz.end()
        ) {
            deckAlice.erase(carta);
            deckBeatriz.erase(carta);
        }
    }

    int trocasPossiveis = 0;
    if (deckAlice.size() >= deckBeatriz.size()) {
        trocasPossiveis = deckBeatriz.size();
    } else {
        trocasPossiveis = deckAlice.size();
    }

    cout << trocasPossiveis << endl;
}
