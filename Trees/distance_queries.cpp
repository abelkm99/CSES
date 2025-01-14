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
  int W = log2(n) + 1;
  vector<vector<int>> parent(n + 1, vector<int>(W, -1));
  vector<vector<int>> G(n + 1);
  vector<int> depth(n + 1, 0);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  function<void(int, int)> calc_depth = [&](int u, int prev) -> void {
    for (int v : G[u]) {
      if (v == prev)
        continue;
      depth[v] = depth[u] + 1;
      parent[v][0] = u;
      calc_depth(v, u);
    }
  };
  calc_depth(1, 0);
  // pre-compute the binary lifting

  for (int p = 1; p < W; p++) {
    for (int i = 2; i <= n; i++) {
      if (parent[i][p - 1] == -1)
        continue;
      parent[i][p] = parent[parent[i][p - 1]][p - 1];
    }
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    int u = a, v = b;
    if (depth[a] < depth[b])
      swap(a, b);
    int diff = depth[a] - depth[b];

    for (int i = W - 1; i >= 0; i--) {
      if ((1 << i) & diff) {
        a = parent[a][i];
      }
    }

    if (a == b) {
      cout << abs(depth[u] - depth[v]) << "\n";
      continue;
    }

    // now we will be looking for thier LCA

    for (int i = W - 1; i >= 0; i--) {
      if (parent[a][i] != parent[b][i]) {
        a = parent[a][i];
        b = parent[b][i];
      }
    }
    a = parent[a][0];
    b = parent[b][0];

    cout << abs(depth[u] - depth[a]) + abs(depth[v] - depth[b]) << "\n";
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
