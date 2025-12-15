#include <bits/stdc++.h>

using namespace std;

int n;
int a[300][300];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> n;


    for(int j=0, curr = 1;j<n;j++){
        if(j%2==0)
            for(int i=0; i <n; i ++ )
                a[i][j] = curr++;
        else
            for(int i=n-1;i>=0;i--)
                a[i][j] = curr++;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout << a[i][j] << " \n"[j==n-1];

    return 0;
}
