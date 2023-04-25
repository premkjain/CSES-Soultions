#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int solve[n + 1];
    memset(solve, 0, sizeof(solve));
    solve[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i >= j){
                solve[i] += solve[i - j];
                solve[i] %= int(1e9 + 7);
            }
        }
    }

    cout << solve[n] << endl;
    return 0;
}