#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n){
    vector<int> seq;
    seq.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(seq.back() < arr[i]){
            seq.push_back(arr[i]);
        }
        else if(seq[seq.size() - 2] < arr[i]){
            seq.pop_back();
            seq.push_back(arr[i]);
        }
    }

    for(auto it : seq){
        cout << it << " ";
    }
    cout << endl;

    return seq.size();
}

int main(){
    int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
    int n = 9;
    cout << lis(arr, n) << endl;
    return 0;
}