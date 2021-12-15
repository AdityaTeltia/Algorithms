#include<bits/stdc++.h>
using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<long long>
#define gi greater<int>
#define endl "\n"
#define pii pair<long long ,long long >

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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



vi adj[100005];
ll LOG = 18 ;
int up[100005][18];
vi depth ;
int sub[100005];

void subtreeSize(ll u , ll p = -1){
	sub[u] = 1;

	for(auto&v : adj[u]){
		if(v == p)
			continue;

		subtreeSize(v , u);
		sub[u] += sub[v]; 
	}


}


void BinaryLifting(int u, int p = -1) {
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int j = 1; j < LOG; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
		BinaryLifting(v, u); 
	}
}


ll LCA(ll x, ll y) {
    if (depth[x] < depth[y]) 
    	swap(x, y);
    
    ll k = depth[x] - depth[y];
    // Step 1: Bring them to the same level
    for (ll j = LOG - 1; j >= 0; j--) {
        if (1 & (k >> j)) x = up[x][j];
    }
    if (x == y) return x;   // If they are already at the same level then return
    // Step 2: Bring both up together
    for (ll j = LOG - 1; j >= 0; j--) {
        if (up[x][j] != up[y][j]) {
            x = up[x][j];
            y = up[y][j];
        }
	}
    return up[x][0];
}




void solve(){

	ll n;
	cin>>n;


	ll u , v;

	for(int i = 0;i<n-1;i++){
		cin>>u>>v;
		--u;--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	depth.resize(n);

	BinaryLifting(0);
	subtreeSize(0);
	debug(depth)

	ll m;
	cin>>m;


	while(m--){
		cin>>u>>v;
		cout<<LCA(u , v)<<endl;


	}







}


int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastio();
    solve();

}	