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
typedef vector<vector<ll>> matrix;
const int K=2;
matrix mul (matrix A, matrix B){
    matrix C(K+1,vector<ll>(K+1));
    for(int i(1);i<=K;++i){
        for(int j(1);j<=K;++j){
           for(int k(1);k<=K;++k){
               C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
               C[i][j]%=mod;
           }
        }
    }
    return C;
}
matrix Pow(matrix A,int p){
    if(p==1)
    return A;
    if(p&1)
    return mul(A,Pow(A,p-1));
    matrix X=Pow(A,p/2);
    return mul(X,X);
}
// returns the nth term of Fibonacci sequence

int fib (int n){
    vector<ll>F(K+1);
    F[1]=1;
    F[2]=1;
    if(n==1)
    return 1;
    matrix T(K+1,vector<ll>(K+1,0));
    T[1][1]=T[1][2]=T[2][1]=1;
    T=Pow(T,n-1);
    ll ans=0;
    for(int i(1);i<=K;++i){
        ans=(ans+F[i]*T[1][i])%mod;
        ans%=mod;
    }
    return ans;
}
void solve() {
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
     
     
    
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