#include<bits/stdc++.h> 
using namespace std;

struct segtree {
    
    int size;   // We need closest power of 2 greater than or equal to n
    vector<long long> sums;

    void init(int n) {
        size=1;
        while(size<n) size*=2;
        sums.assign(2*size, 0ll);
    }

    void build(vector <int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if (lx < (int)a.size()) {
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        sums[x] = sums[2*x+1] + sums[2*x + 2];
    }
    void build(vector <int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx)/2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2*x + 2];
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }


    long long sum(int l, int r, int x, int lx, int rx) {
        if(r <= lx or l >= rx) {
            return 0;
        }
        if(rx <= r and lx >= l) {
            return sums[x];
        }
        
        int m = (lx + rx)/2;
        long long lsum = sum(l, r, 2*x+1, lx, m);
        long long rsum = sum(l, r, 2*x+2, m, rx);
        return lsum+rsum;
    }
    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        int v;
        cin >> a[i]; 
    }
    st.build(a);

    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
        }
    }

    return 0;
}