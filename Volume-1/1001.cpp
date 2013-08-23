#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

static const int MAXN = 256 * 1024 / 2 + 1;
static double v[MAXN];

int main() {
  long long x;
  int i = 0;
  while(scanf("%lld", &x) > 0) {
    v[i++] = sqrt((double)x);
  }
  for(i = i - 1; i >= 0; i--) {
    printf("%.4lf\n", v[i]);
  }
  return 0;
}
