/*
Standard Binary Lifting question
Since algo is standard and good tutorials are available online so no need the explain
One wierd stuff I encountered was that time limit for this problem were very strict so I had to use int everywhere instead of long long
So if you are also getting TLE on problems of CSES consider changing all the long long to normal ints
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
 
vector<vll> reach;
 
void solve(){
    ll n,q;
    cin >> n >> q;
    reach.assign(n + 1,vll(35));
    rep(i,1,n + 1){
        ll x;
        cin >> x;
        reach[i][0] = x; //Update the dist of 1 (2^0) from initial point
    }
    rep(j,1,32){
        rep(i,1,n + 1){
            reach[i][j] = reach[reach[i][j - 1]][j - 1]; //Using binary lifting concept get the distance of 2,4,8,16... from all the points
        }
    }
    rep(i,0,q){
        ll str;
        long long int dist;
        cin >> str >> dist;
        ll up = 0;
        while(dist){       //Using bitmasking get the final ans
            if((dist&1LL)){
                str = reach[str][up];
            }
            up++;
            dist >>= 1LL;
        }
        cout << str << br;
 
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
 
