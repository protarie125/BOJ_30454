#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

ll n, l;
vl counts;

ll CountLine(const string& s) {
  auto ret = 0LL;
  auto z = s[0];

  if ('1' == z) {
    ++ret;
  }

  for (auto i = 1ULL; i < s.size(); ++i) {
    if (z != s[i] && '1' == s[i]) {
      ++ret;
    }

    z = s[i];
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> l;
  counts = vl(n);

  auto mx = 0LL;
  for (auto i = 0; i < n; ++i) {
    string s;
    cin >> s;
    const auto& now = CountLine(s);
    mx = max(mx, now);

    counts[i] = now;
  }

  auto ans = 0LL;
  for (const auto& x : counts) {
    if (x == mx) {
      ++ans;
    }
  }

  cout << mx << ' ' << ans;

  return 0;
}