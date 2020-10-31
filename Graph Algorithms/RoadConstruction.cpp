/*
Sandard application of Disjoint Set Union
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
    ll n,m;
    cin >> n >> m;
    parent.resize(n + 1);
    size.resize(n + 1);
    rep(i,1,n + 1) make_set(i);
    ll maxi = 1,t = n;
    rep(i,0,m){
        ll a,b;
        cin >> a >> b;
        if(find_set(a) != find_set(b)){
            union_sets(a,b);
            t--;
            maxi = max(maxi,size[find_set(a)]);
        }
        cout << t << " " << maxi << br;
    }
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
