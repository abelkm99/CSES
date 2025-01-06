#include <algorithm>
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

using pr = pair<int, int>;
using pq = vector<pr>;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  vector<pq> contribution(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // dfs 1 initialization
  // answer for the root node and continue to do so
  function<int(int, int)> pre_calc = [&](int u, int parent) -> int {
    for (int v : graph[u]) {
      if (v == parent) {
        continue;
      }
      int res = pre_calc(v, u);
      contribution[u].push_back({res, v});
      push_heap(all(contribution[u]));
    }
    return (contribution[u].size() > 0 ? contribution[0][0].first : 0) + 1;
  };
  pre_calc(0, -1);

  vector<int> ans(n, 0);

  dbg(contribution);
  dbg(string(20, '-'));

  function<void(int, int)> dfs = [&](int u, int parent) -> void {
    ans[u] = contribution[u].size() ? contribution[u][0].first : 0;
    dbgm(u, ans[u], contribution[u]);

    for (int v : graph[u]) {
      if (v == parent)
        continue;

      pq u_contrib = contribution[u];
      pq v_contrib = contribution[v];

      if (contribution[u].size() and contribution[u][0].second == v) {
        pop_heap(all(contribution[u]));
        contribution[u].pop_back();
      }
      if (contribution[u].size()) {
        contribution[v].push_back({contribution[u][0].first + 1, u});
        push_heap(all(contribution[v]));
      }

      dfs(v, u);
      // now reset everything to where it was before
      contribution[u] = u_contrib;
      contribution[v] = v_contrib;
    }
  };
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
