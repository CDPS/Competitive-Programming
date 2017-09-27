#include <bits/stdc++.h>

using namespace std;

long long a[100000];

int main(){
    int n;

    scanf("%d",&n);

    long long mini= 1000000001;

    int res;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] < mini){
            mini=a[i];
            res=i;
        }
    }

    bool f=1;
    for(int i=0;i<n;i++){
        if(a[i]== mini && res!=i){
            f=0;
            break;
        }
    }

    if(f)cout << res+1 << "\n";
    else cout << "Still Rozdil\n";
    return 0;
}
