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



#define read(args...) read1(args)
#define out(args...) out1(args)
#define sortf(args...) sortf1(args)
#define sortr(args...) sortr1(args)

void read1() {return; }
template<typename T, typename... Args>
void read1(T &a, Args&... args) {for (auto &i : a) cin >> i; read1(args...); }

void out1() {return; }
template<typename T, typename... Args>
void out1(T &a, Args&... args) {for (auto &i : a) cout<<i<<" "; cout<<endl; out1(args...); }

void sortf1(){return ;}
template<typename T, typename... Args>
void sortf1(T &a, Args&... args) {sort(a.begin(), a.end()); sortf1(args...); }

void sortr1(){return ;}
template<typename T, typename... Args>
void sortr1(T &a, Args&... args) {sort(a.rbegin(), a.rend()); sortr1(args...); }


void solve(){

    ll n , m;
    cin>>n;


    vector<vector<ll>>graph(n+1 , vector<ll>(n+1 , INF));


    ll a , b , c;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++)
            cin>>graph[i][j];
    }

    

    debug(dp)

    while(q--){
        cin>>a>>b;
        if(dp[a][b] == INF){
            cout<<-1<<endl;
        }else{
            cout<<dp[a][b]<<endl;
        }
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