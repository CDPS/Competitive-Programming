#include <bits/stdc++.h>

using namespace std;

int a [100];
int main(){
    int n;
    scanf("%d",&n);

    int maxi=-1;
    for(int i=0;i<n;i++){
        scanf("%d", a +i );
        if(a[i]>maxi){
            maxi = a[i];
        }
    }

    int res =0;
    for(int i=0;i<n;i++) res+= maxi-a[i];

    printf("%d\n",res);
    return 0;
}
