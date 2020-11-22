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
const int N=1e5+2;
vi a(N);
vi x(N);
vi y(N);
int r,n;

vi dp(N,0);         // Stores the maximum photos taken when last photo is of ith celebrity
vi pref(N,0);       // Storing the maximum element from previous dp indices

int solve(int i,int j) {
    
    for(int i=1;i<=n;i++)
    {
        // debug(i);
        if(a[i]>=x[i]+y[i]-2)        // If the man can reach ith celebrity
        {
            dp[i]=1;
            
            for(int j=i-1;j>0;j--)
            {
                if(a[i]-a[j]>=2*r)
                {
                    dp[i]=max(pref[j]+1,dp[i]);     // Used prefix to get the max element from the previous dp indices
                    break;
                }
                if(a[i]-a[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]))  // If from the jth we can go to ith
                {
                    dp[i]=max(dp[i],dp[j]+1);       // Then photos of ith would be max of (i-th) and (photos of j-th)+1
                }
                // debug(i,j,dp[i]);
            }
        }
        else
        {
            dp[i]=INT_MIN;
        }
        pref[i]=max(pref[i-1],dp[i]);
    }
    return *max_element(dp.begin(),dp.begin()+n+1);
}

int32_t main()
{
    FIO;
    cin>>r>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];  // time
        cin>>x[i];
        cin>>y[i];
    }
    a[0]=0;
    x[0]=1;
    y[0]=1;
    
    int ans= solve(0,1);
    cout<<ans;
}