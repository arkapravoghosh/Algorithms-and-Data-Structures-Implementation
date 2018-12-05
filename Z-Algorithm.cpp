#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vpii vector<pii >
#define vpll vector<pll >
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define rep(i, j, k) for(int i = j; i < k; ++i)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)
 
const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;
const int MAX = (int)1e5;

vi z_calc(string s) { // this function builds the z-array
    int n = (int)s.size();
    vi z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i) {
        if(i <= r) 
            z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) 
            ++z[i];
        if(i+z[i]-1 > r) 
            l = i, r = i+z[i]-1;
    }
    return z;
}
 
int main() {
    fastio;
    T {
        int n, m; // n is the length of the given text and m is the length of the pattern to be searched within the text
        cin >> n >> m;
        string s, t; // s is the given text and t is the pattern to be searched for in the text
        cin >> s >> t;
        t += "#" + s; // we append the pattern t in front of the text s with a delimiter '#' which is not present in either of the strings
        vi z = z_calc(t);
        int c = 0; // will keep track of the number of occurances of the pattern in the text
        for(int i = m+1; i < z.size(); i++)
            if(z[i] == m) // if the length of the substring starting at index i which is also a prefix of the string has a length equal to that of the pattern then the pattern is found 
                c++;
        cout << c << '\n';
    }
    return 0;
}
