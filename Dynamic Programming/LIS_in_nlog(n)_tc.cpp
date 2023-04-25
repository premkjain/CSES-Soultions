#include <bits/stdc++.h>
using namespace std;

int mybs(int arr[], int T[], int end, int s){
    int start = 0;
    int len = end;
    while(start <= end){
        int middle = (start + end)/2;
        if(middle < len && arr[T[middle]] < s && s <= arr[T[middle + 1]]){
            return middle + 1;
        }
        else if(arr[T[middle]] < s){
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }
    return -1;
}

vector<int> lis(int arr[], int n){
    int T[n];
    int R[n];
    memset(R, -1, sizeof(R));
    T[0] = 0;
    int len = 0;

    for(int i = 1; i < n; i++){
        if(arr[T[0]] > arr[i]){
            T[0] = i;
        }
        else if(arr[T[len] < arr[i]]) {
            len++;
            T[len] = i;
            R[T[len]] = T[len-1];
        }
        else {
            int ind = mybs(arr, T, len, arr[i]);
            T[ind] = i;
            R[T[ind]] = T[ind - 1];
        }
    }

    int ind = T[len];
    vector<int> ans;
    while(ind != -1){
        ans.push_back(arr[ind]);
        cout << arr[ind] << " ";
        ind = R[ind];
    }
    cout << endl;
    return ans;
}

int main(){
    int arr[] = {3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};
    int n = 11;
    vector<int> ans = lis(arr, n);
    cout << ans.size() << endl;
    return 0;
}