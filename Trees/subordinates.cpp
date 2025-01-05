#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbgv(...)
#define dbg(...)
#define dbgr(...)
#define dbgm(...)
#endif
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5 + 10;
vector<int> Graph[N];

int ANS[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    Graph[i].clear();
    ANS[i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    Graph[p].push_back(i);
  }
  function<void(int)> dfs = [&](int u) -> void {
    for (int v : Graph[u]) {
      dfs(v);
      ANS[u] += 1 + ANS[v];
    }
  };
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << ANS[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  clock_t z = clock();
#endif
  int T = 1;
  while (T-- > 0) {
    solve();
  }
#ifdef LOCAL
  cout << ((double)(clock() - z) / CLOCKS_PER_SEC) << " seconds!";
#endif
  return 0;
}
