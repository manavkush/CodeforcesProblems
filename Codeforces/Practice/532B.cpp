#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FIO     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

int main()
{
    FIO;
    int n,m;
    cin>>n>>m;
    set<int> s;
    int a[n+2]={0};
    re1(i,1,m)
    {
        int temp;
        cin>>temp;
        a[temp]++;
        s.insert(temp);
        if(s.size()==n)
        {
            cout<<1;
            re1(j,1,n)
            {
                a[j]--;
                if(!a[j])
                    s.erase(j);
            }
            
        }
        else cout<<0;
    }

}