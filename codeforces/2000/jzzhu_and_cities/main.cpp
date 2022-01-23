#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

using TUP = tuple<int, int, bool>;

int n, m, k;

const int N = 1e5 + 9;
vector<vector<TUP>> paths(N);
vector<pair<int64_t, bool>> dist(N, {1e9 + 7, false});
priority_queue<int> pq;
VI trains(N, 0);

auto solve() -> void {
  cin >> n >> m >> k;

  for (int i = 0; i < m; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    paths[u].PB({v, x, false});
    paths[v].PB({u, x, false});
  }

  for (int i = 0; i < k; ++i) {
    int s, y;
    cin >> s >> y;
    paths[1].PB({s, y, true});
    ++trains[s];
  }

  dist[1].first = 0;
  pq.push(1);
  while (pq.size() > 0) {
    auto curr = pq.top();
    pq.pop();
    for (size_t i = 0; i < paths[curr].size(); ++i) {
      auto [dest, weight, is_t] = paths[curr][i];
      auto curr_dist = dist[curr].first;
      auto dest_dist = dist[dest].first;

      bool c1 = curr_dist + weight < dest_dist;
      bool c2 = curr_dist + weight == dest_dist && !is_t && dist[dest].second;
      if (c1 || c2) {
        dest_dist = curr_dist + weight;
        dist[dest].second = is_train;
        pq.push(dest);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += trains[i];
    if (dist[i].second) ans -= 1;
  }

  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
