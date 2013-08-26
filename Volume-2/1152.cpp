#include <iostream>
#include <cstring>

using namespace std;

static const int MAXN = 20, INF = 1e9;
static int n;
static int a[MAXN];
static int D[1 << MAXN];

int solve(unsigned s, int sum) {
	if(D[s] == -1) {
		D[s] = INF;
		for(int i = 0; i < n; i++) {
			unsigned cs = s;
			int lSum = sum;
			for(int k = 0; k < 3; k++) {
				cs = (cs & (~((1 << ((i + k) % n)))));
				if((s & ((1 << ((i + k) % n))))) {
					lSum -= a[(i + k) % n];
				}
			}
			if(cs != s) {
				D[s] = min(D[s], lSum + solve(cs, lSum));
			}
		}
	}
	return D[s];
}

int main() {
	int sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	memset(D, -1, sizeof D);
	D[0] = 0;
	cout << solve((1 << n) - 1, sum) << endl;
	return 0;
}
