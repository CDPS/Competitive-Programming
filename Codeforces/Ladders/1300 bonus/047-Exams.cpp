#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin >> n >> k;

    if(k >= n * 3){
        cout << 0 << "\n";
    }
    else{
        cout  << n - (k- (n * 2)) << "\n";
    }
    return 0;
}
