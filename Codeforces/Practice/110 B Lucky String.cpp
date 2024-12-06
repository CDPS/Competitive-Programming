#include <bits/stdc++.h>

using namespace std;

char a[4] = {'a','b', 'c', 'd'};
int main(){

    int n;
    cin >> n;
    string ans;

    for(int i=0;i<n;i++)
        ans +=a[i%4];

    cout << ans << "\n";
}
