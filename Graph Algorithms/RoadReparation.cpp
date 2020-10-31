/*
Standard question of finding minimum spanning tree
Since good tutorials are already on internet no need for further explanation of this question
*/
 
 
#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
    
#define ll long long int
#define ld double
#define pb push_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define pre(i , j , n) for(ll i = j ; i >= n ; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<char>	vc;
typedef vector<bool>	vb;
typedef pair<ll,ll> 	pll;
#define br "\n"
#define ff first
#define ss second
#define MAXIM 1000005 
ll mod = 1e9 + 7;

vll parent,size;
ll n,m;
void make_set(ll v) {
    parent[v] = v;
    size[v] = 1;
}

ll find_set(ll v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
 
void solve(){
    cin >> n >> m;
    set<pair<ll,pll>> edge;
    parent.resize(n + 1);
    size.resize(n + 1);
    rep(i,1,n + 1) make_set(i);
    rep(i,0,m){
        ll a,b,w;
        cin >> a >> b >> w;
        edge.insert({w,{a,b}});
    }
    ll ans = 0;
    ll t = 0;
    for(auto &x:edge){
        ll u = x.ss.ff,v = x.ss.ss,w = x.ff;
        if(find_set(u) != find_set(v)){
            ans += w;
            t++;
            union_sets(u,v);
        }
    }
    if(t != n - 1) cout << "IMPOSSIBLE\n";
    else cout << ans << br;
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
 
	ll t = 1;
	// cin >> t;
	rep(i,0,t){
        // cout << "Case #" << i + 1 << ": ";
		solve();
        // test();
	}
 
}
