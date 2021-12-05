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
#define pii pair<ll,ll>
 
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
 
 
vector<pii>adj[200005];
 
 
void solve(){
 
    int n , m , a , b , w;
    cin>>n>>m;
 
 
    while(m--){
        cin>>a>>b>>w;
        adj[a].pb({b,w});
    }
 
 
    priority_queue<pii,vector<pii>,greater<pii>>pq;
 
    vi dist(n+1 , INF);
 
    pq.push({0,1}); // { dist , node_value}
    dist[1] = 0;
 
    while(!pq.empty()){
        ll curr = pq.top().ss;
        ll curr_d = pq.top().ff;
        pq.pop();
        if(curr_d != dist[curr])
            continue;
 
        for(pii edge  : adj[curr]){
            // edge = {node_value , weight};
 
            if(curr_d + edge.ss < dist[edge.ff]){
                dist[edge.ff] = curr_d + edge.ss;
                pq.push({dist[edge.ff] , edge.ff});
            }
 
 
        }
 
    }
 
    for(int i = 1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
 
}
 
 
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
 
}