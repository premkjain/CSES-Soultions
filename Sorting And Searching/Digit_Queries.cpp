#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")

#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define BigInt      __int128
#define endl        '\n'
#define mii         map<ll int,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007
#define N           200005
#define INF         1e18
#define PI          3.141592653589793238462

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll int, null_type, less<ll int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key


pii helper(ll int idx){
    for(ll int i = 1; i <= 18; i++){
        ll int t = 9 * i * pow(10, i - 1);
        if(idx - t <= 0){return {idx, i};}
        idx -= t;
    }
    return {idx, 19};
}


void solve(){
    ll int idx;
    cin >> idx;
    ll int len;
    tie(idx, len) = helper(idx);
    idx--;
    ll int ele_pos = idx / len;
    ll int i = idx - ele_pos * len;
    ll xpow = pow(10, len - 1);
    ll ele = (ll)(pow(10, len - 1)) + ele_pos;
    string ele_str = to_string(ele);
    cout << ele_str[i] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    cin>>TESTS;
    // cerr << "---" << endl;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}