// Problem Link - https://cses.fi/problemset/task/1137/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+1;

vector<int> G[MAX], order, ind(MAX), sz(MAX);
vector<long long> v(MAX), tree(4*MAX);

void dfs(int u, int p) {
    ind[u] = order.size();
    order.push_back(u);
    sz[u] = 1;
    for(int v : G[u]) {
        if(v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = v[order[l]];
        return;
    }
    int m = (l+r)>>1;
    build(node<<1, l, m);
    build(node<<1|1, m+1, r);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

void update(int node, int l, int r, int idx, long long val) {
    if(l > idx || r < idx)
        return;
    if(l == r && r == idx) {
        tree[node] = val;
        return;
    }
    int m = (l+r)>>1;
    update(node<<1, l, m, idx, val);
    update(node<<1|1, m+1, r, idx, val);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

long long query(int node, int l, int r, int p, int q) {
    if(l > q || r < p)
        return 0;
    if(l >= p && r <= q)
        return tree[node];
    int m = (l+r)>>1;
    return query(node<<1, l, m, p, q) + query(node<<1|1, m+1, r, p, q);
}

int main() {
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

    dfs(1, 0); // process the nodes for subtrees, given 1 is the root node
    build(1, 0, n-1); // build the segment tree on the values array for the subtree queries

    while(q--) { 
        int ch;
        cin >> ch;

        if(ch == 1) { // QUERY TYPE 1 - change the value of node s to x
            int s;
            long long x;
            cin >> s >> x;
            update(1, 0, n-1, ind[s], x);
        } else if(ch == 2) { // QUERY TYPE 2 - find the sum of values in the subtree of node s
            int s;
            cin >> s;
            cout << query(1, 0, n-1, ind[s], ind[s] + sz[s] - 1) << '\n';
        }
    }
  
    return 0;
}
