#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;

bool is_prime(int n) {
  int i = 2;
  while (i < n) {
    if (n % i == 0) return false;
    ++i;
  }
  return true;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s = 2;
    LPI(i, 0, n, 1) {
      while (!is_prime(s)) {
        ++s;
      }
      cout << s << ' ';
      ++s;
    }
    cout << '\n';
  }

  return 0;
}
