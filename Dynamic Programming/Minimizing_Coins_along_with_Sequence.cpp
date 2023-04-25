#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, target_sum;
    cin >> n >> target_sum;
    int coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    int solve[target_sum + 1];
    int first[target_sum + 1];

    solve[0] = 0;
    first[0] = 0;

    for(int x = 1; x <= target_sum; x++){
        solve[x] = INT_MAX;
        for(int i = 0; i < n; i++){
            if(x >= coins[i] && solve[x - coins[i]] + 1 < solve[x]){
                solve[x] = solve[x - coins[i]] + 1;
                first[x] = coins[i];
            }
        }
    }

    cout << solve[target_sum] << endl;
    while(target_sum > 0){
        cout << first[target_sum] << " ";
        target_sum -= first[target_sum];
    }
    cout << endl;

    return 0;
}