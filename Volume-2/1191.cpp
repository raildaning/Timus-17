#include <iostream>

using namespace std;

static const int MAXN = 101;
static int k[MAXN];

int main () {
	int n, l;
	bool ans = false;
	cin >> l >> n;
	for(int i = 0; i < n; i++) {
		cin >> k[i];
	}
	int t, p;
	t = k[0]; p = l;
	for(int i = 1; i <= n; i++) {
		if(t > p) {
			cout << "YES\n";
			return 0;
		}
		int x = 1 + ((p - t) / k[i - 1]);
		p = t + x * k[i - 1];
		t = t + k[i];	
	}
	cout << "NO\n";
	return 0;
}
