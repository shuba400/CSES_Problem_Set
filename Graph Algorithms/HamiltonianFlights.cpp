/*
Idea :- 
This is not really a graph question but more of a standard dp question.
So lets say that a mask m = 110101 denotes if we have visited city(by 1) or not(by 0).

Now I am having a dp state dp[ind][mask] which says that in the given mask, what are the number
of ways to visit all the city in given mask with "ind" being the last city that we visit from the mask.
Now for question we have to calculate dp[n][11111111].
Transition is fairly straight forward
dp[ind][m] += summation(dp[x][(ind^m)]) provided x --> n.
and for base case

dp[1][1000000] = 1;

that is at start only one way is there to start from 1 with only 1 city visited.

Implementation details :-
All the states and transition of dp states are already defined above
only minor detail is that instead of storing the child of a given node, 
we are going to store the parent of a given node
*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define _USE_MATH_DEFINES
#define _MATH_DEFINES_DEFINED
using namespace __gnu_pbds;
using namespace std;
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
    
#define ll int
#define ld long double
#define pb push_back
#define eb emplace_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define pre(i , j , n) for(ll i = j ; i >= n ; i--) 
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<double>	vd;
typedef vector<bool>	vb;
typedef pair<ll,ll> 	pll;
typedef vector<vector<ll>> vvll;
#define M_PI       3.14159265358979323846
#define br "\n"
#define ff first
#define ss second
#define MAXIM 1000101
const ll MAX = 2e5 + 1;
const ll mod = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": "; _print(x); cerr<< endl;
#else
#define debug(x);
#endif

void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll n,m,tot;
vvll g;
vvll dp;

ll bin_exp(ll a, ll b){
    a = a % mod;
    ll ans = 1;
    while(b > 0){
        if(b & 1 == 1) ans = (a * ans) % mod;
        a = (a * a) % mod;
        b = b >> 1; 
    }
    return ans;
}

ll mod_inv(ll n){
    ll a = bin_exp(n,mod - 2);
    return a;
}

ll sub(ll a,ll b){
    return ((a - b + mod) % mod);
}

ll mul(ll a,ll b){
    return ((a*b)%mod);
}

ll add(ll a,ll b){
    return ((a+b)%mod);
}

ll divide(ll a,ll b){
    return((a*mod_inv(b)) % mod);
}

ll cal(ll ind,ll m){
    if(dp[ind][m] >= 0) return dp[ind][m];
    ll t = 0;
    ll x = (m ^ (1LL << ind));
    for(auto &i:g[ind]){
        if(i == ind) continue;
        if(((1LL<<i)&x) == 0) continue;
        ll tmp = cal(i,x);
        t += tmp;
        if(t >= mod) t %= mod;
    }
    dp[ind][m] = t;
    return dp[ind][m];
}

void solve(){
    cin >> n >> m;
    tot = (1 << n);
    dp.resize(n,vll(tot,-1));
    g.resize(n);
    rep(i,0,m){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        g[b].pb(a);
    }
    dp[0][1] = 1;
    cout << cal(n - 1,tot - 1) << br;

}
 
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
    #endif
 
    ll t = 1;
    // cin >> t;
    rep(i,0,t){
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // test();
    }
}
