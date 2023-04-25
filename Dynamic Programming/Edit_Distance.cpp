/* ____                       _  __                     _       _       _       
  |  _ \ _ __ ___ _ __ ___   | |/ /__ _ _ __ ___   __ _| |     | | __ _(_)_ __  
  | |_) | '__/ _ \ '_ ` _ \  | ' // _` | '_ ` _ \ / _` | |  _  | |/ _` | | '_ \ 
  |  __/| | |  __/ | | | | | | . \ (_| | | | | | | (_| | | | |_| | (_| | | | | |
  |_|   |_|  \___|_| |_| |_| |_|\_\__,_|_| |_| |_|\__,_|_|  \___/ \__,_|_|_| |_|
*/                                                                            

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;

#define hell    1000000007
#define PI      3.141592653589793238462
#define INF     1e18
#define vi      vector<ll>
#define pb      push_back
#define ppb     pop_back
#define mii     map<ll,ll>
#define pii     pair<ll,ll>
#define mp      make_pair
#define ff      first
#define ss      second
#define all(x)  (x).begin(), (x).end()

/*____________________________________________________________________________________________________________________________________________________________________________________________________*/
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*____________________________________________________________________________________________________________________________________________________________________________________________________*/

void solve()
{
    string s, t;
    cin >> s >> t;

    vector<vi> dp(s.size() + 1, vi(t.size() + 1, 0));
    for(ll i = 0; i <= s.size(); i++){
        for(ll j = 0; j <= t.size(); j++){
            if(i == 0 || j == 0){
                dp[i][j] = i + j;
            }
            else if (s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }

    cout << dp[s.size()][t.size()] << endl;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for(ll i = 0; i < t; i++){
        solve();
    }
    return 0;
}