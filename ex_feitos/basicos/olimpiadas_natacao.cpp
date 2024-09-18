#include <bits/stdc++.h>

using namespace std;


int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tempos;
    for (int i=0; i<3; i++) {
        int tempo;
        cin >> tempo;
        tempos.push({tempo, i+1});
    }
    for (int i=0; i<3; i++) {
        cout << tempos.top().second << endl;
        tempos.pop();
    }
}
