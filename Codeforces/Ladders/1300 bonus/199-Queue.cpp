#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    sort(a, a + n);

    int acc =0;
    int res =0;
    for(int i = 0;i < n;i++){
        if(a[i]>=acc){
            acc+=a[i];
            res++;
        }
    }
    cout  << res << "\n";
    return 0;
}

