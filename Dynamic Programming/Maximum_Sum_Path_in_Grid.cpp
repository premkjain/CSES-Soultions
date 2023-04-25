#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
bool done[1001][1001];
int grid[1001][1001];

int sum(int x, int y, int n){
    if(x < 0 || y < 0 || x > n || y > n){
        return 0;
    }
    if(done[x][y]){
        return dp[x][y];
    }

    int ans = -1;
    if(x > 0){
        ans = max(ans, sum(x - 1, y, n) + grid[x][y]);
    }
    if(y > 0){
        ans = max(ans, sum(x, y - 1, n) + grid[x][y]);
    }

    done[x][y] = true;
    dp[x][y] = ans;
    return ans;
}

int main(){
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    memset(done, false, sizeof(done));
    dp[0][0] = grid[0][0];
    done[0][0] = true;

    int ans = sum(n - 1, n - 1, n);
    cout << ans << endl;
    return 0;
}