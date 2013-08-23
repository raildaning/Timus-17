#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> pii;
static const int INF = 1000;

void myTransform(vector<pii>& pos, int mx, int my) {
	int n = pos.size();
	for(int i = 0; i < n; i++) {
		swap(pos[i].first, pos[i].second);
		pos[i].first = my - pos[i].first;
		pos[i].second = pos[i].second - mx;
	}
}

void placeChar(vector<string>& A, vector<pii>& pos, char c) {
	int n = A.size();
	int m = n > 0 ? A[0].size() : 0;
	int l = pos.size();
	for(int i = 0; i < l; i++) {
		A[pos[i].first][pos[i].second] = c;
	}
}

void print(vector<string>& A) {
	int n = A.size();
	for(int i = 0; i < n; i++) {
		cout << A[i] << '\n';
	}
}

int main() {
	
	int maxX = 0, maxY = 0, minX = 0, minY = 0;
	int n;
	vector<pii> v;
	
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		maxX = max(v[i].first, maxX);
		maxY = max(v[i].second, maxY);
		minX = min(v[i].first, minX);
		minY = min(v[i].second, minY);
	}

	vector<string> A;
	string line(maxX - minX + 1, '.');
	A.resize(maxY - minY + 1, line);

	vector<pii> aux;
	for(int i = minX; i <= maxX; i++) {
		aux.push_back(pii(i, 0));
	}
	myTransform(aux, minX, maxY);
	placeChar(A, aux, '-');
	aux.clear();

	for(int i = minY; i <= maxY; i++) {
		aux.push_back(pii(0, i));
	}
	myTransform(aux, minX, maxY);
	placeChar(A, aux, '|');
	aux.clear();

	aux.push_back(pii(0, 0));
	myTransform(aux, minX, maxY);
	placeChar(A, aux, '+');
	aux.clear();

	myTransform(v, minX, maxY);
	placeChar(A, v, '*');

	print(A);

	return 0;
}
