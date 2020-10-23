/* 
Standard Bellman Ford Algo
Overview - Apply Bellman ford algo and after nth iteration check for all the
nodes whose distance changes.
Mark these nodes as visited and then reverse the adjancy list
Then do a DFS from last node and check if any visited node is reachable from nth node

Why does this works?
Question basically asks us to check if there is any negative cycle in the path of
start node to end node. So using DFS we checking exactly if any node whose distance
can be altered from starting node is reachable from ending node or not.
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

vector<vector<pll>> grid;
ll n,m;
vll dist;
vb vis,reach;
vector<vll> dep;

bool found = false;

void dfs(ll u){
    if(reach[u]) return;
    reach[u] = true;
    if(vis[u]) found = true;
    for(auto &x:dep[u]){
        dfs(x);
    }
}

ll bfs(){
    bool change; //Checks if a negative cycle is present or not
    rep(k,0,n - 1){
        change = false;   //Standard Bellman ford for n - 1 iteration
        rep(i,1,n + 1){
            if(dist[i] == 1e18) continue;
            for(auto &x:grid[i]){
                if(dist[x.ff] > dist[i] + x.ss){
                    dist[x.ff] = dist[i] + x.ss;
                    change = true;
                }
            }
        }
        if(!change) break;
    }
    if(!change) return change; //No need to waste more time if there was no change
    dep.resize(n + 1);   //Procedure for Reversing adjacency and do a BFS 
    reach.assign(n + 1,false);
    vis.assign(n + 1,false);
    rep(i,1,n + 1){
        if(dist[i] == 1e18) continue;
        for(auto &x:grid[i]){
            if(dist[x.ff] > dist[i] + x.ss){
                dist[x.ff] = dist[i] + x.ss;
                vis[x.ff] = true;
            }
        }
    }
    rep(i,1,n + 1){
        for(auto &x:grid[i]){
            dep[x.ff].pb(i);
        }
    }
    dfs(n);
    change = found;
    return change;
}

void solve(){
    cin >> n >> m;
    grid.resize(n + 1);
    dist.assign(n + 1,1e18);
    rep(i,0,m){
        ll a,b,w;
        cin >> a >> b >> w;
        grid[a].pb({b,-1LL*w}); //Storing negative of edge weights
    }
    dist[1] = 0;
    if(bfs()) cout << -1 << br;
    else cout << -1*dist[n] << br;

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
