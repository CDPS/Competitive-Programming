#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;

int calc(char c){
    int ans = 0, acc = 0;
    for(int i=0, j=0;i<n;i++){
        while( j < n){
            if(s[j]== c && acc== k) break;
            if(s[j]== c) acc++;
            j++;
        }
        ans = max(ans, j-i);
        acc = (s[i]==c)? acc - 1 : acc;
    }
    return ans;
}

int main(){
    cin >> n >> k;
    cin >> s;
    cout << max ( calc('b') , calc('a')) <<"\n";
    return 0;
}
