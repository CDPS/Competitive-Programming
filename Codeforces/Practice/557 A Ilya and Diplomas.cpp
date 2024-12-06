#include <bits/stdc++.h>

using namespace std;

int a[3][2];

int main(){

    int n;
    cin >> n;
    for(int i=0;i<3;i++)
        cin >> a[i][1] >> a[i][0];

    if(a[0][0] + a[1][1] + a[2][1] > n)
        cout << n - (a[1][1] + a[2][1]) << " " <<  a[1][1] << " " << a[2][1] << "\n";
    else if(a[0][0] + a[1][0] + a[2][1] >  n )
        cout << a[0][0] << " " <<  n- (a[0][0]+a[2][1]) << " " << a[2][1] << "\n";
    else
         cout << a[0][0] << " " <<  a[1][0] << " " << n-(a[0][0]+a[1][0]) << "\n";
    return 0;
}
