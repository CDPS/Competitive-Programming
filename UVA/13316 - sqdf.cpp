#include <bits/stdc++.h>

using namespace std;

bool solve(int n){
    for(int i=0;i<=200;i++)
        for(int j=i+1; j<=200;j++)
            if((j*j)-(i*i) == n )
                return true;
    return false;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;
    while(cin >> n && n){
        cout << (solve(n)? "Y":"N") << "\n";
    }
    return 0;
}
