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

void solve() { 
  int n, q;
  cin >> n >> q;
  int w = log2(n) + 1;

  vector<vector<int>> dp(n + 1, vector<int>(w, -1));
  vector<vector<int>> g(n + 1);
  vector<int> depth(n + 1);

  for (int i = 2; i <= n; i++) {
    int u; cin >> u;
    g[u].push_back(i);
    g[i].push_back(u);
    // make my parrent the node u
    dp[i][0] = u;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < sz(dp[i]); j++) {
      if (dp[i][j - 1] == -1) continue;
      dp[i][j] = dp[dp[i][j - 1]][j-1];
    }
  }

  depth[1] = 0;
  function<void(int, int)> dfs = [&](int u, int prev) -> void {
    for (int v: g[u]) {
      if (v == prev) continue;
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  };
  dfs(1, 0);

  while(q--) {
    int u, v;
    cin >> u >> v;

    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];

    for (int i = w - 1; i >= 0; i--) {
      if ((1 << i) & diff) {
        u = dp[u][i];
      }
    }

    if (u == v) {
      cout << u << "\n";
      continue;
    }

    for (int i = w - 1; i >= 0; i--) {
      if (dp[u][i] != dp[v][i]) {
        u = dp[u][i];
        v = dp[v][i];
      }
    }

    cout << dp[u][0] << "\n";
  }

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
