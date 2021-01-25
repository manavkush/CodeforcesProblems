#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
const int mod = 1000000007;
//===================================DEBUG TEMPLATE=================================================
void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//====================================DEBUG TEMPLATE==============================================
vector<pii> adj[505];
int matrix[505][505];
int n,m;
const int MAXVAL = 1e15;

int32_t main()
{
    FIO;
    cin>>n>>m;
    int q;
    cin>>q;
    re(i,505) {
        re(j,505) {
            if(i==j) {
                matrix[i][j]=0;
            } else {
                matrix[i][j] = MAXVAL;
            }
        }
    }

    re(i,m) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});

        // debug(matrix[a][b],c);
        matrix[a][b] = min(matrix[a][b],c);
        matrix[b][a] = matrix[a][b];
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int k=1;k<=n;k++)  {
        for(int j=1;j<=n;j++) {
            for(int i=1;i<=n;i++) {
                matrix[i][j] = min(matrix[i][k]+matrix[k][j],matrix[i][j]);
                // matrix[j][i] = matrix[i][j];
            }
        }
    }
    while(q--) {
        int a,b;
        cin>>a>>b;
        if(matrix[a][b]== MAXVAL) {
            cout<<-1<<endl;
        } else {
            cout<<matrix[a][b]<<endl;
        }
    }

    
}