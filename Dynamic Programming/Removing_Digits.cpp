#include <bits/stdc++.h>
using namespace std;

vector<int> digits(int n){
    vector<int> ans;
    while(n != 0){
        int x = n % 10;
        ans.push_back(x);
        n /= 10;
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,INT_MAX - 1);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        vector<int> x = digits(i);
        for(auto it : x){
            int left = i - it;
            if(left >= 0){
                dp[i] = min(dp[i], dp[left] + 1);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}