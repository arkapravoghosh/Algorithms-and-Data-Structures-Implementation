#include <stdio.h>
#include <stdbool.h>

const int MAX = (int)1e3;

int parent[1000];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool same(int u, int v) {
    return find(u) == find(v);
}

void merge(int u, int v) {
    parent[v] = find(u);
}

int kruskals(int u[], int v[], int w[], int n, int m) {
    for(int i = 0; i <= n; ++i) parent[i] = i;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m-i-1; ++j)
            if(w[j] > w[j+1]) {
                int t = w[j]; w[j] = w[j+1]; w[j+1] = t;
                t = u[j]; u[j] = u[j+1]; u[j+1] = t;
                t = v[j]; v[j] = v[j+1]; v[j+1] = t;
            }
    int wt = 0;
    for(int i = 0; i < m; ++i) {
        printf("%d ", i);
        fflush(stdout);
        if(!same(u[i], v[i])) {
            wt += w[i];
            merge(u[i], v[i]);
        }
    }
    return wt;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int u[m], v[m], w[m];
	for(int i = 0; i < m; ++i) 
	    scanf("%d %d %d", &u[i], &v[i], &w[i]);
	int mst_wt = kruskals(u, v, w, n, m);
	printf("The MST weight is %d", mst_wt);
	return 0;
}

