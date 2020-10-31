/*
Prerequistics for this questions were to know how to detect cycle in a graph using coloring concept
Now since each node has only 2 edges so it makes sense that any connected component will have exactly
one cycle
Now in any connected component few nodes might be inside or a part of that cyle and other might not be a part of that cycle
Example 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 4
Over here 4,5 and 6 are part of cycle while 1,2,3 are not
So whatever will be the answer will be for 4 it will be the answer for 5 and 6 too(As all are in cycle) and answer is equal to number of nodes
in cycle(in this case 3)
And for rest of the nodes in connected component it will be the sum of number of nodes in cycle + distance of this node to the nearest node which
was the part of cycle

So now we just need to take care of 2 things - if a node is a part of cycle or not
*/
#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
    
#define ll int
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
 
vector<vll> grid;
vll col,ans,lvl;
ll par = -1;
ll cycle = 0;
 
void dfs(ll u,ll l = 0){
    col[u] = 1;     
    lvl[u] = l;
    for(auto &x:grid[u]){
        if(col[x] == 2){  //If a node is already visited in a connected component that means cycle have already been found earlier
            cycle = 1;  //updating that cycle have been found that is now answer of each successive node will increase by 1
            ans[u] = ans[x] + cycle;
            continue; 
        }
        if(col[x] == 1){    //Once we find the stating node of cycle update the parent of that cycle
            par = x;
            ans[u] = lvl[u] - lvl[x] + 1;
            continue;
        }
        dfs(x,l + 1);
        ans[u] = ans[x] + cycle;
    }
    if(par == u) cycle = true;
    col[u] = 2;
}
 
void solve(){
    ll n;
    cin >> n;
    grid.resize(n + 1);
    col.resize(n + 1);
    ans.resize(n + 1);
    lvl.resize(n + 1);
    rep(i,1,n + 1){
        ll x;
        cin >> x;
        grid[i].pb(x);
    }
    rep(i,1,n + 1){
        cycle = 0;
        if(col[i] == 0) dfs(i);
 
    }
    rep(i,1,n + 1) cout << ans[i] << " ";
 
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
