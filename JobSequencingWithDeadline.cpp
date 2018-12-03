#include <iostream>
using namespace std;

const int MAX = (int)1e3;

int parent[MAX];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    parent[v] = find(u);
}

int main() {
    int n;
    cout << "Enter the no of jobs:";
    cin >> n;
    for(int i = 0; i <= n; ++i) parent[i] = i;
    int deadline[n], profit[n];
    for(int i = 0; i < n; ++i) {
        cout << "Enter the deadline and profit of job " << i << ": ";
        cin >> deadline[i] >> profit[i];
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n-i-1; ++j)
            if(profit[j] < profit[j+1]) {
                swap(profit[j], profit[j+1]);
                swap(deadline[j], deadline[j+1]);
            }
    int total = 0;
    for(int i = 0; i < n; ++i) {
        int u = find(deadline[i]);
        if(u > 0) {
            total += profit[i];
            merge(u-1, u);
        }
    }
    cout << "\nThe maximum possible profit is " << total << ".";
}
