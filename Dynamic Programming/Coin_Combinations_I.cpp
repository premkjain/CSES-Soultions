#include <bits/stdc++.h>
using namespace std;

int coins[101];
int value[1000001];
bool done[1000001];

int solve(int target_sum, int n){
    if(target_sum == 0){
        return 1;
    }
    else if(target_sum < 0){
        return 0;
    }
    if(done[target_sum] == true){
        return value[target_sum];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += solve(target_sum - coins[i], n);
        ans %= int(1e9 + 7);
    }

    done[target_sum] = true;
    value[target_sum] = ans;
    
    return ans;
}

int main(){
    int n, target_sum;
    cin >> n >> target_sum;
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    int ans = solve(target_sum, n);
    cout << ans << endl;
    return 0;
}