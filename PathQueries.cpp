#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+1;

vector<int> G[MAX], order, ind(MAX), sz(MAX);
vector<long long> v(MAX), sum(MAX), BIT(2*MAX);

void dfs(int u, int p) {
    order.push_back(u);
    ind[u] = order.size();

    sz[u] = 1;
    sum[u] = sum[p] + v[u];
    
    for(int c : G[u]) {
        if(c != p) {
            dfs(c, u);
            sz[u] += sz[c];
        }
    }
}

void add(int n, int idx, long long val) {
    while(idx <= n) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}

void constructTree(int bitsz, int n) {
    for(int i = 1; i <= n; ++i)
        add(bitsz, i, sum[i]);
}

void update(int n, int l, int r, long long val) {
    add(n, l, val);
    add(n, r+1, -val);
}

long long query(int n, int idx) {
    long long res = 0, r = idx, l = idx-1;

    while(idx > 0) {
        res += BIT[idx];
        idx -= idx & (-idx);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q; // input the number of nodes in the tree and the number of queries
    
    for(int i = 1; i <= n; ++i) // input the values of each node
        cin >> v[i];

    for(int i = 1; i < n; ++i) { // input the edges of the tree
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    long long bitsz = 1;
    while(bitsz < n)
        bitsz *= 2;

    dfs(1, 0); // process the nodes for subtrees, given 1 is the root node
    constructTree(bitsz, n); // construct the binary index tree on the sum array for the path queries

    while(q--) { 
        int ch;
        cin >> ch;

        if(ch == 1) { // QUERY TYPE 1 - change the value of node s to x
            int s;
            long long x;
            cin >> s >> x;

            update(bitsz, ind[s], ind[s] + sz[s] - 1, x-v[s]);
            v[s] = x;
        }
        else if(ch == 2) { // QUERY TYPE 2 - find the sum of values on the path from root to node s
            int s;
            cin >> s;

            cout << query(bitsz, ind[s]) << '\n';
        }
    }
    return 0;
}
