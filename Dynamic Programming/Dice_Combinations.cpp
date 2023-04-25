#include <bits/stdc++.h>
using namespace std;

int value[1000001];
bool done[1000001];

int solve(int x){
    if(x == 0){
        return 1;
    }
    else if(x < 0){
        return 0;
    }
    if(done[x] == true){
        return value[x];
    }

    int ans = 0;
    for(int i = 1; i <= 6; i++){
        ans += solve(x - i);
        ans %= int(1e9+7);
    }

    value[x] = ans;
    done[x] = true;

    return ans;
}

int main(){
    int n;
    cin >> n;

    memset(value, 0, sizeof(value));
    memset(done, false, sizeof(done));
    
    int ans = solve(n);
    cout << ans << endl;
    return 0;
}