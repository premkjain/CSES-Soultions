#include <bits/stdc++.h>
using namespace std;

int hell = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == '*'){
                grid[i][j] = 1;
            }
        }
    }

    vector<vector<int>> dp(n, vector<int> (n, 0));
    if(grid[0][0] == 0){
        dp[0][0] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                continue;
            }
            if(i > 0){
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= hell;
            }
            if(j > 0){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= hell;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;
    return 0;
}