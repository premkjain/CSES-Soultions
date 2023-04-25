#include <bits/stdc++.h>
using namespace std;

int value[1000001];
bool done[1000001];
int coins[1000001];

int solve(int target_sum, int num_coins){
    if(target_sum == 0){
        return 0;
    }
    else if(target_sum < 0){
        return INT_MAX - 1;
    }
    else if(done[target_sum] == true){
        return value[target_sum];
    }
    
    for(int i = 0; i < num_coins; i++){
        value[target_sum] = min(value[target_sum], solve(target_sum - coins[i], num_coins)+1);
    }

    done[target_sum] = true;
    return value[target_sum];
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins, coins + n);
    memset(value, 1000001, sizeof(value));
    memset(done, false, sizeof(done));

    value[0] = 0;
    done[0] = true;

    int ans = solve(m, n);
    if(ans == 1094795585){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}