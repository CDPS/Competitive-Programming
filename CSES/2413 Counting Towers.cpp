#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;

int t, n;

int solve(int i, int j){

    if(i == n && j == n) return 1;
    if(i > n || j > n)   return 0;

    return solve(i+1, j) + solve(i, j+1) + ((i==j)? solve(i+1,j+1) : 0);
}
int main(){

    cin >> t;
    while(t--){
        cin >> n;
        cout  << solve(0, 0) << "\n";
    }

    return 0;
}
