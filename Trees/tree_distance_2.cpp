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
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  dbg(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<ull> children(n, 0), total(n, 0), ans(n, 0);

  function<void(int, int)> precalc = [&](int u, int p) -> void {
    children[u] = 1;
    for (int v : g[u]) {
      if (v == p)
        continue;
      precalc(v, u);
      children[u] += children[v];
      total[u] += total[v] + children[v];
    }
    // total[u] += children[u];
    return;
  };

  function<void(int, int)> dfs = [&](int u, int p) -> void {
    ans[u] = total[u];
    for (int v : g[u]) {
      if (v == p)
        continue;

      // it was this that its failing to do the process so
      ll t_contrib = total[v] + children[v];
      ll c_contrib = children[v];
      total[u] -= t_contrib;
      children[u] -= c_contrib;

      children[v] += children[u];
      total[v] += children[u] + total[u];
      dfs(v, u);

      total[u] += t_contrib;
      children[u] += c_contrib;

    }
  };

  precalc(0, -1);
  dbgm(total);
  dbgm(children);
  dfs(0, -1);
  for (auto &x : ans) {
    cout << x << " ";
  }
  cout << "\n";
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
