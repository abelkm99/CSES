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

const int N = 2e5 + 5;
vector<int> G[N];
void solve() {

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    G[i].clear();
  }
  while (--n) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  // start from the root node and get the deepest one
  // start from the deepest node and get the other deepest one
  function<pair<int, int>(int, int)> get_max;
  get_max = [&](int u, int prev) -> pair<int, int> {
    dbgm(u, prev);
    pair<int, int> ans = {0, u};
    for (int v : G[u]) {
      if (v == prev)
        continue;
      ans = max(ans, get_max(v, u));
    }
    ans.first += 1;
    return ans;
  };
  auto [d, node] = get_max(1, -1);

  cout << get_max(node, -1).first - 1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  // freopen("Error.txt", "w", stderr);
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
