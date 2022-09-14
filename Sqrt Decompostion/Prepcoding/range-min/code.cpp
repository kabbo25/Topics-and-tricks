
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long, long long>
#define ull unsigned long long
#define ll int64_t
#define ar array
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// const int mod = 1e9 + 7;
using u64 = uint64_t;
using u128 = __uint128_t;
#define sc1(x) scanf("%lld", &(x));
auto random_address = [] {
  char *p = new char;
  delete p;
  return uint64_t(p);
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() *
               (random_address() | 1));
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifndef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
/*Well, probably you won't understand anything,
because you didn't try to understand anything in your life,
you expect all hard work to be done for you by someone else.
Let's start*/
template <class T> istream &operator>>(istream &is, vector<T> &v) {
  for (int i(0); i < (int)v.size(); ++i)
    is >> v[i];
  return is;
}
const int inf = 2e9;
void solve() {
  int n, Q;
  cin >> n >> Q;

  vector<int> v(n);
  for (auto i = 0; i < n; ++i) {
    cin >> v[i];
    // dbg(v[i]);
  }
  int sz = (int)ceil(sqrt(n + 1));

  vector<int> block(sz, inf);
  for (int i(0); i <= n; ++i) {
    int block_number = i / sz;
    block[block_number] = min(block[block_number], v[i]);
  }
  // dbg(Q,n);
  for (auto i = 0; i < Q; ++i) {
    int l, r;
    cin >> l >> r;
    int ans = inf;
    for (int j(l); j < r;) {
      if ((j % sz == 0) and (j + sz - 1 < r)) {
        ans = min(ans, block[j / sz]);
        j += sz;
      } else {
        ans = min(ans, v[j]);
        j++;
      }
    }
    cout << ans << endl;
  }
}
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}