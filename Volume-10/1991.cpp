#include <iostream>

using namespace std;

int main() {
  int n, k, a, dleft = 0, bleft = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a;
    bleft += max(0, a - k);
    dleft += max(0, k - a);
  }
  cout << bleft << " " << dleft << endl;
  return 0;
}
