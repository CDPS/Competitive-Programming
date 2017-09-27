#include <bits/stdc++.h>

using namespace std;

int a[11];

int main(){


    int t,caseno=1;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        printf("Case %d: %d\n",caseno++,a[(n/2)] );
    }

    return 0;
}
