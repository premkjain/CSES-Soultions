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
    ll a, b;
    cin >> a >> b;

    vector<vi> dp(a + 1, vi(b + 1, hell));
    for(ll i = 1; i <= a; i++){
        for(ll j = 1; j <= b; j++){
            ll mini = hell;
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(ll k = 1; k <= (i + 1) / 2; k++){
                mini = min(mini, 1 + dp[k][j] + dp[i - k][j]);
            }
            for(ll k = 1; k <= (j + 1) / 2; k++){
                mini = min(mini, 1 + dp[i][k] + dp[i][j - k]);
            }

            dp[i][j] = mini;
        }
    }

    cout << dp[a][b] << endl;
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