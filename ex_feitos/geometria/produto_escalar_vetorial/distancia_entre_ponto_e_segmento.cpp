#include <bits/stdc++.h>

using namespace std;



double distancia(pair<double, double> &A, pair<double, double> &B) {
	return sqrt(pow(A.first-B.first, 2) + pow(A.second-B.second, 2));
};


double distanciaReta(pair<double, double> &A, pair<double, double> &B, pair<double, double> &P) {
	return abs((P.first-A.first)*(B.second-A.second)-(P.second-A.second)*(B.first-A.first))/distancia(A, B);
};


double distanciaSegmento(pair<double, double> &A, pair<double, double> &B, pair<double, double> &P) {
	if ((B.first-A.first)*(P.first-A.first) + (B.second-A.second)*(P.second-A.second) < 0) return distancia(P, A);
	if ((A.first-B.first)*(P.first-B.first) + (A.second-B.second)*(P.second-B.second) < 0) return distancia(P, B);
	return distanciaReta(A, B, P);
};


int main() {
	pair<double, double> A, B, P;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> P.first >> P.second;

	cout << distanciaSegmento(A, B, P) << endl;
}
