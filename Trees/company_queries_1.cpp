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
  // cout << "got here\n";
  vector<vector<int>> table(n + 1, vector<int>(w, -1));
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    table[i][0] = u;
  }

  // do the table pre preocessing
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < sz(table[i]); j++) {
      if (table[i][j - 1] == -1)
        continue;
      table[i][j] = table[table[i][j - 1]][j - 1];
    }
  }

  while (q--) {
    int node, jmp;
    cin >> node >> jmp;

    for (int i = 20; i >= 0; i--) {
      if ((1 << i) & jmp) {
        // if this set bit is on
        node = table[node][i];
        if (node == -1) {
          break;
        }
      }
    }
    cout << node << "\n";
  }
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
