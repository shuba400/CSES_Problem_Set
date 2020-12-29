/*
This is a standard application of Strongly Connected Components(SCC) in graph.For solving this question all you need to know is what exactly is Strongly Connected Component.
Since this is simple application I have linked down some resources to understand SCC

https://cp-algorithms.com/graph/strongly-connected-components.html#toc-tgt-3

So you must have read about SCC, now only thing left in this question is to check is number of SCC in graph. 
If nums(SCC) == 1 we can simply print the answer else we have to print no and check for non reachable nodes.
How to check non reachable nodes? 
Simple - Take elements of 2 SCCs(node u and v),Run a dfs from u and check if we can reach node v or not
If we cannot than by deafult answer will be u v
Else answer will be v u.(Think about this on your own)
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
typedef vector<double>	vd;
typedef vector<bool>	vb;
typedef pair<ll,ll> 	pll;
#define br "\n"
#define ff first
#define ss second
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;
ll MAX = 1e6 + 1;
ll mod = 1e9 + 7;

stack<ll> s;
vector<vll> g1,g2,comp;
vb vis;

void dfs1(ll u){
    vis[u] = 1;
    for(auto &x:g1[u]){
        if(vis[x]) continue;
        dfs1(x);
    }
    s.push(u);
}

void dfs2(ll u,vll &v){
    vis[u] = 1;
    for(auto &x:g2[u]){
        if(vis[x]) continue;
        dfs2(x,v);
    }
    v.pb(u);
}

void solve(){
    ll n,m;
    cin >> n >> m;
    g1.resize(n + 1);
    g2.resize(n + 1);
    vis.assign(n + 1,false);
    rep(i,0,m){
        ll a,b;
        cin >> a >> b;
        g1[a].pb(b);
        g2[b].pb(a);
    }
    rep(i,1,n + 1){
        if(!vis[i]) dfs1(i);
    }
    vis.clear();
    vis.assign(n + 1,false);
    while(!s.empty()){
        ll i = s.top();
        s.pop();
        if(!vis[i]){
            vll temp;
            dfs2(i,temp);
            comp.pb(temp);
        }
    }
    if(comp.size() == 1){
        cout << "YES" << br;
        return;
    }
    vis.clear();
    vis.assign(n + 1,false);
    ll u = comp[0][0],v = comp[1][0];
    dfs1(u);
    cout << "NO" << br;
    if(vis[v]) cout << v << " " << u;
    else cout << u << " " << v;  
}
 

int main(){ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
	ll t = 1;
    // calc();
    // cin >> t;
    // calc();
	rep(i,0,t){
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // test();
	}
}
