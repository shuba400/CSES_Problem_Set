/*
Dijikstra Algo 
So first of find the shortest distance of a every node from node 1 and shortest
distance of every node from node N
Then consider all the edges
Now this edge will be from node u to node v
So find the distance from 1 to node u and node v to node n 
Then add the distance of nodeu to nodev by 2

So basically we are considering all the edges for applying coupon and optimizing 
it using dijiktra
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
#define MAXIM 200005 
ll mod = 998244353LL;

vector<vector<pll>> grid1,grid2;
vector<pair<pll,ll>> edge;
vll dist1,dist2;
ll n,m;

void bfs1(){
    dist1[1] = 0;
    set<pll> s;
    s.insert({dist1[1],1});
    while(!s.empty()){
        pll fir = *s.begin();
        s.erase(s.begin());
        ll t = fir.ss;
        ll d = fir.ff;
        for(auto &x:grid1[t]){
            if(dist1[x.ff] > d + x.ss){
                if(s.find({dist1[x.ff],x.ff}) != s.end()) s.erase({dist1[x.ff],x.ff});
                dist1[x.ff] = d + x.ss;
                s.insert({dist1[x.ff],x.ff});            
            }  
        }
    }
}

void bfs2(){
    dist2[n] = 0;
    set<pll> s;
    s.insert({dist2[n],n});
    while(!s.empty()){
        pll fir = *s.begin();
        s.erase(s.begin());
        ll t = fir.ss;
        ll d = fir.ff;
        for(auto &x:grid2[t]){
            if(dist2[x.ff] > d + x.ss){
                if(s.find({dist2[x.ff],x.ff}) != s.end()) s.erase({dist2[x.ff],x.ff});
                dist2[x.ff] = d + x.ss;
                s.insert({dist2[x.ff],x.ff});            
            }  
        }
    }
}

void solve(){
    cin >> n >> m;
    grid1.resize(n + 1);
    grid2.resize(n + 1);
    dist1.assign(n + 1,1e18);
    dist2.assign(n + 1,1e18);
    rep(i,0,m){
        ll a,b,w;
        cin >> a >> b >> w;
        grid1[a].pb({b,w});
        grid2[b].pb({a,w});
        edge.pb({{a,b},w});
    }
    ll ans = 1e18;
    bfs1();
    bfs2();
    for(auto &x:edge){
        ll temp = dist1[x.ff.ff] + dist2[x.ff.ss] + (x.ss/2);
        ans = min(ans,temp);
    }
    cout << ans << br;



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
