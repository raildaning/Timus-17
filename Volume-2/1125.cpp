#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int m, n;
char a[66][66];
int f[66][66];

char op[256];
bool isSquare[10000];

int main() {
	op['B'] = 'W';
	op['W'] = 'B';
	for(int i = 0; i < 100; i++) {
		isSquare[i * i] = true;
	}
	cin >> m >> n;
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> f[i][j];
		}
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				for(int l = 0; l < n; l++) {
					if(isSquare[(i - k) * (i - k) + (j - l) * (j - l)] && (f[i][j] & 1)) {
						a[k][l] = op[a[k][l]];
					}
				}
			}
		}
	}
	for(int i = 0; i < m; i++) {
		cout << a[i] << '\n';
	}
	return 0;
}
