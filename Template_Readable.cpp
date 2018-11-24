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
#define rep(i, j, k) for(int i = j; i < k; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;
const int MAX = (int)(1e5+1);

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return (max(a,b) / gcd(a,b)) * min(a,b);
}

bool isPrime(ll n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(ll i = 5; i*i <= n; i += 6)
        if(n%i == 0 || n%(i+2) == 0) return false;
    return true;
}

vll primes;
void find_primes(ll n = 100000000) { //Segmented-sieve
    ll limit = floor(sqrt(n)) + 1;
    vll test; test.pb(2), primes.pb(2);
    for(ll i = 3; i < limit; i += 2)
        if(isPrime(i)) test.pb(i), primes.pb(i);
    ll lo = limit, hi = 2*limit; bool p[limit];
    while(lo < n) {
        if(hi > n) hi = n; 
        memset(p, true, sizeof(p));
        for(int i = 0; i < test.size(); i++) {
            ll mn = floor(lo/test[i]) * test[i];
            if(mn < lo) mn += test[i];
            for(ll j = mn; j < hi; j += test[i]) p[j-lo] = 0;
        }
        for(ll i = 0; i < limit; i++)
            if(p[i] && i+lo < hi) primes.pb(i+lo);
        lo += limit, hi += limit;
    }
}

ll modmult(ll a, ll b) {
    ll res = 0;
    a %= MOD;
    while(b > 0) {
        if(b%2 == 1) res = (res + a)%MOD;
        a = (2 * a)%MOD;
        b /= 2;
    }
    return res%MOD;
}

ll modexpo(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b > 0) {
        if(b%2 == 1) res = (res * a)%MOD;
        a = (a * a)%MOD;
        b /= 2;
    }
    return res%MOD;
}

bool sec(const pll &a, const pll &b) { 
    return (a.ss < b.ss);
}

ll nCr(ll n, ll r) {
    ll res = 1;
    if(r > n>>1) r = n-r;
    rep(i, 0, r) {
        res = (res * (n-i))%MOD;
        res = (res * modexpo(i+1, MOD-2))%MOD;
    }
    return res;
}

ll naturalNumInverse[MAX + 1], factorialNumInverse[MAX + 1], fact[MAX + 1]; 
void binomial_pre() {
    //Inverse of Number
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= MAX; i++) 
        naturalNumInverse[i] = naturalNumInverse[MOD % i] * (MOD - MOD / i) % MOD; 
    //Inverse of Factorial | n! = n*(n-1)! => inv(n!) = inv(n) * inv((n-1)!)
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= MAX; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % MOD; 
    //Factorial
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD; 
}
  
ll binomial(ll n, ll r) {
    if(n < r) return 0;
    return ((fact[n] * factorialNumInverse[r]) % MOD * factorialNumInverse[n - r]) % MOD;
}
 
int main() {
    fastio;
    //find_primes();
    //binomial_pre();
    T {
        
    }
    return 0;
}    
