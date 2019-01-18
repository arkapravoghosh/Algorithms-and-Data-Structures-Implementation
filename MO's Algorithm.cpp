//Problem - https://www.spoj.com/problems/DQUERY/
//Solution:-

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vll vector<ll>
#define vull vector<ull>
#define vpii vector<pll >
#define vpll vector<pll >
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define rep(i, j, k) for(ll i = j; i < k; ++i)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)
 
const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;
const int MAX = (int)(1e6+1);
 
ll coun[MAX] = {0}, a[MAX], ans = 0, block;
 
inline void add(int pos) {
    ++coun[a[pos]];
    if(coun[a[pos]] == 1) ++ans;
}
 
inline void remove(int pos) {
    --coun[a[pos]];
    if(coun[a[pos]] == 0) --ans;
}
 
int main() {
    fastio;
    int n, q;
    cin >> n;
    block = sqrt(n);
    rep(i, 0, n) cin >> a[i];
    cin >> q;
    vector<pair<pii, int>> b(q);
    ll res[q];
    rep(i, 0, q) {
        cin >> b[i].ff.ff >> b[i].ff.ss;
        --b[i].ff.ff, --b[i].ff.ss;
        b[i].ss = i;
    }
    sort(all(b), [](auto &x, auto &y) {
            if(x.ff.ff/block != y.ff.ff/block) //queries belong to diff blocks
                return x.ff.ff < y.ff.ff;
            return x.ff.ss < y.ff.ss;
        });
    int l = 0, r = 0;
    for(auto v : b) {
        int x = v.ff.ff, y = v.ff.ss;
        while(l < x) {
            remove(l);
            ++l;
        }
        while(l > x) {
            add(l-1);
            --l;
        }
        while(r <= y) {
            add(r);
            ++r;
        }
        while(r > y+1) {
            remove(r-1);
            --r;
        }
        res[v.ss] = ans;
    }
    rep(i, 0, q) cout << res[i] << '\n';
    return 0;
} 
