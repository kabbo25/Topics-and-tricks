/*
* @Author: kabbo
* @Date:   2020-06-24 08:40:07
* @Last Modified by:   kabbo
* @Last Modified time: 2020-06-24 08:49:58
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define endl '\n'
#define ull unsigned long long
#define ll int64_t
#define ar array
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
const int mod = 1e9 + 7;
using u64 = uint64_t;
using u128 = __uint128_t;
#define sc1(x) scanf("%lld",&(x));
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
/*Well, probably you won't understand anything,
because you didn't try to understand anything in your life,
you expect all hard work to be done for you by someone else. 
Let's start*/
struct node{
    int min,max,sum;
};
node seg[20];
int arr[20];
int getSegmentTreeSize(int N) {
  int size = 1;
  for (; size < N; size <<= 1);
  return size << 1;
}
node assign_leaf(int x){
       node ans;
       ans.min=x;
       ans.max=x;
       ans.sum=x;
       return ans;
}
node merge(node left,node right){
    node ans;
    ans.min=min(left.min,right.min);
    ans.max=max(left.max,right.max);
    ans.sum=left.sum+right.sum;
    return ans;
}
void build(int stindex,int lo,int hi){
    if(lo==hi){
        seg[stindex]=assign_leaf(arr[lo]);
        return;
    }
    int left=2*stindex,right=left+1,mid=(lo+hi)/2;
    build(left,lo,mid);
    build(right,mid+1,hi);
    seg[stindex]=merge(seg[left],seg[right]);
}

void solve() {
  int n;
  cin>>n;
  for(int i(1);i<=n;++i){
      cin>>arr[i];
  }
  build(1,1,n);
  for(int i(1);i<=15;++i)
     cout<<i<<" "<<seg[i].min<<" "<<seg[i].max<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin>>t;
    // for (int i(1); i <= t; ++i) {
        //printf("Case %d:\n", i);
        solve();
   // }
    return 0;
}