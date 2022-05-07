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

int maze[18][18];
int path[18][18];

bool validPos(int n, int row, int col) {
    bool rowValid = (row >= 0) && (row < n);
    bool colValid = (col >= 0) && (col < n);

    return (rowValid && colValid) && (maze[row][col] == 1) && (path[row][col] == 0);
}

void ratInMaze(int n, int row, int col) {
    if (row == n - 1 && col == n - 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << path[i][j] << " ";
            }
        }
        cout << "\n";
        return;
    }


    if (validPos(n, row-1, col)) { // up
        path[row-1][col] = 1;
        ratInMaze(n, row-1, col);
        path[row-1][col] = 0;
    }
    if (validPos(n, row+1, col)) {  // down
        path[row+1][col] = 1;
        ratInMaze(n, row+1, col);
        path[row+1][col] = 0;
    }
    if (validPos(n, row, col-1)) {  // left
        path[row][col-1] = 1;
        ratInMaze(n, row, col-1);
        path[row][col-1] = 0;
    }
    if (validPos(n, row, col+1)) {  // right
        path[row][col+1] = 1;
        ratInMaze(n, row, col+1);
        path[row][col+1] = 0;
    }

}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            path[i][j] = 0;
        }
    }
    path[0][0] = 1;

    ratInMaze(n, 0, 0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio()
    int t = 1;
    while(t--) {
        solve();
    }
    
    return 0;
}

// TODO TCA