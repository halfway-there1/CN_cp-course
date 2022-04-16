#include "bits/stdc++.h"
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
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

bool canTakeAtleastHalf(ll n, ll k) {
    ll half = (n % 2 == 0) ? (n >> 1) : ((n+1) >> 1);
    ll cntSharma = 0;
    while (n > 0) {
        if (n >= k) {
            n -= k;
            cntSharma += k;
        } else {
            cntSharma += n;
            break;
        }
        
        n -= n / 10;
    }

    return (cntSharma >= half);
}

/* bool canTakeAtleastHalf(ll n, ll k) {
    ll temp = n;
    ll cntSharma = 0;
    while (n > 0) {
        cntSharma += min(n, k);
        n = n - k;
        n = n - (n / 10);
    }

    return ((cntSharma << 1) >= temp);
} */

void solve() {
    ll n;
    cin >> n;

    ll low = 1;
    ll high = (n % 2 == 0) ? (n >> 1) : ((n+1) >> 1);
    ll mid;
    ll minimalK = high;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (canTakeAtleastHalf(n, mid)) {
            minimalK = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << minimalK << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio()
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}