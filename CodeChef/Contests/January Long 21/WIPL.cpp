#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i, n) for (int i = 0; i < (n); i++)
#define re1(i, k, n) for (int i = k; k < n ? i <= n : i >= n; k < n ? i += 1 : i -= 1)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
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
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
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
int n, k;
const int inf = 1e8;
vi pref;

int dp[4002][8000];
bool vis[4002][8000];
// vector<vi> dp(4002, vi(8000, 0));
// vector<vi> vis(4002, vi(8000, 0));

vector<int> a;
int solve(int sum1, int ind) {
    int sum2 = pref[ind] - sum1;
    if (sum1 >= k and sum2 >= k) {
        return ind;
    } else if (ind >= n) {
        return inf;
    } else if (vis[ind][sum1]) {
        return dp[ind][sum1];
    } else {
        vis[ind][sum1] = 1;

        if (sum1 >= k) {
            dp[ind][sum1] = solve(sum1, ind + 1);
        } else if (sum2 >= k) {
            dp[ind][sum1] = solve(sum1 + a[ind], ind + 1);
        } else {
            dp[ind][sum1] = min(solve(sum1 + a[ind], ind + 1), solve(sum1, ind + 1));
        }
        return dp[ind][sum1];
    }
}

int32_t main() {
    FIO;
    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        cin >> n >> k;
        pref.resize(n + 1, 0);
        a.resize(n, 0);
        re(i, n) {
            cin >> a[i];
        }
        sort(all(a), greater<int>());
        re(i, n) {
            pref[i + 1] = pref[i] + a[i];
        }
        if (a[0] >= k) {
            int count = 1;
            int sum = 0;
            int flag = 0;
            for (int i = 1; i < n; i++) {
                sum += a[i];
                count++;
                if (sum >= k) {
                    flag = 1;
                    break;
                }
            }
        }
        int ans = solve(0, 0);
        if (ans > n) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}
