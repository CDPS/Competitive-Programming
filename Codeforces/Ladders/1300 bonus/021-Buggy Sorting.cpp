#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    if(n == 1 || n==2){
        cout << "-1" << "\n";
    }else{

        cout << n;
        for(int i=n-1;i>=1;i--)
            cout << " " << i;
        cout << "\n";
    }
    return 0;
}
