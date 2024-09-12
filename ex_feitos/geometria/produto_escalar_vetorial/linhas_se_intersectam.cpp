#include <bits/stdc++.h>

#define ll long long

using namespace std;


bool clockwise(pair<ll, ll> vertice, pair<ll, ll> referencia, pair<ll, ll> comparacao) {
	return (referencia.first-vertice.first)*(comparacao.second-vertice.second) - (referencia.second-vertice.second) * (comparacao.first-vertice.first) < 0;
}


int main() {
	pair<ll, ll> I1, F1, I2, F2;

	cin >> I1.first >> I1.second;
	cin >> F1.first >> F1.second;
	cin >> I2.first >> I2.second;
	cin >> F2.first >> F2.second;

	cout << (
		(clockwise(I1, F1, I2) != clockwise(I1, F1, F2))
		&& (clockwise(I2, F2, I1) != clockwise(I2, F2, F1))
	) << endl;
}
