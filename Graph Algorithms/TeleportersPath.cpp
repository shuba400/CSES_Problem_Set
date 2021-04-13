/*
    This question has a use of a concept of finding euler circuit/path.
    Good resource- https://cp-algorithms.com/graph/euler_path.html
    Now after understanding this concept it is easy to see that we can extend this concept for our question  
    by adding a dummy node x which goes from x ---> 1 .....something ---> n --> x
    This dummy node has only one out going edge to 1 and only one incoming edge from n
    Thus we have converted this problem to finding a the euler circuit for above graph with starting node as x
    Now if euler cicuit exists we can print the answer ignoring first an last value of path.
*/





#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define _USE_MATH_DEFINES
#define _MATH_DEFINES_DEFINED
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
    
#define ll long long int
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
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;
#define working cout << "Working till here" << endl;
#define MAXIM 1000101
const ll MAX = 2e5 + 1;
ll mod = 1e9 + 7;

vector<set<ll>> g;
vll in,out,ans;
ll n,m;

void dfs(ll u){
    while(g[u].size()){
        ll t = *g[u].begin();
        g[u].erase(t);
        dfs(t);
    }
    ans.pb(u);
}

void solve(){
    cin >> n >> m;
    n++;
    g.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    rep(i,0,m){
        ll a,b;
        cin >> a >> b;
        g[a].insert(b);
        out[a]++;
        in[b]++;
    }
    g[n].insert(1);
    out[n]++;
    in[1]++;
    g[n - 1].insert(n);
    out[n - 1]++;
    in[n]++;
    rep(i,1,n + 1){
        if(in[i] != out[i]){
            cout << "IMPOSSIBLE" << br;
            return;
        }
    }
    dfs(n);
    if(ans.size() != m + 3){
        cout << "IMPOSSIBLE" << br;
        return;
    }
    pre(i,ans.size() - 2,1) cout << ans[i] << " ";

}
 
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
 
    ll t = 1;
    // cin >> t;
    rep(i,0,t){
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // test();
    }
}
