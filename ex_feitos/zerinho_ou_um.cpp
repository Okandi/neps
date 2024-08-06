#include <bits/stdc++.h>

using namespace std;


int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B && A == C) cout << "*";
    else if (A == B) cout << "C";
    else if (A == C) cout << "B";
    else cout << "A";
}
