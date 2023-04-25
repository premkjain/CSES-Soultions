#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, target_sum;
    cin >> n >> target_sum;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(target_sum+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= target_sum; j++){
            int left = j - x[i - 1];
            dp[i][j] = dp[i - 1][j];
            if(left >= 0){
                dp[i][j] += dp[i][left];
                dp[i][j] %= int(1e9 + 7);
            }
        }
    }

    cout << dp[n][target_sum] << endl;
    return 0;
}