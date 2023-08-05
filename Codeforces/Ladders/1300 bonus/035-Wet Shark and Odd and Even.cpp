#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    cin >> n;
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum%2==0){
        cout << sum << "\n";
    }else{
        int index = -1;
        sort(a, a + n);

        for(int i=0;i<n;i++){
            if(a[i]%2){
                index = i;
                break;
            }
        }
        cout << sum  - a[index]<< "\n";
    }
}
