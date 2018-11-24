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
const int MAX = (int)(1e5+1);

vll primes;
ll nI[MAX],fI[MAX],fact[MAX];

ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}          
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return 0;return 1;}
void find_primes(ll n = 100000000){ll limit=floor(sqrt(n))+1;vll test;test.pb(2),primes.pb(2);for(ll i=3;i<limit;i+=2)if(isPrime(i))test.pb(i),primes.pb(i);ll lo=limit,hi=2*limit;bool p[limit];while(lo<n){if(hi>n)hi=n;
memset(p,true,sizeof(p)); for(int i=0;i<test.size();++i){ll mn=(lo/test[i])*test[i];if(mn<lo)mn+=test[i];for(ll j=mn;j<hi;j+=test[i])p[j-lo]=0;}rep(i,0,limit)if(p[i] && i+lo<hi)primes.pb(i+lo); lo+=limit,hi+=limit;}}
ll modmult(ll a,ll b){ll res=0;a%=MOD;while(b){if(b&1)res=(res+a)%MOD;a=(a<<1)%MOD;b>>=1;}return res;}
ll modexpo(ll a,ll b){ll res=1;a%=MOD;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
bool sec(const pll &a,const pll &b){return (a.ss<b.ss);}
ll nCr(ll n,ll r){ll res=1;if(r>n>>1)r=n-r;rep(i,0,r){res=(res*(n-i))%MOD;res=(res*modexpo(i+1,MOD-2))%MOD;}return res;}
void binomial_pre(){nI[0]=nI[1]=fI[0]=fI[1]=fact[0]=1;rep(i,2,MAX)nI[i]=nI[MOD%i]*(MOD-MOD/i)%MOD;rep(i,2,MAX)fI[i]=(nI[i]*fI[i-1])%MOD;rep(i,1,MAX)fact[i]=(fact[i-1]*i)%MOD;}
ll binomial(ll n,ll r){if(n<r)return 0;return ((fact[n]*fI[r])%MOD*fI[n-r])%MOD;}

int main() {
    fastio;
    //find_primes();
    //binomial_pre();
    T {
        
    }
    return 0;
}
