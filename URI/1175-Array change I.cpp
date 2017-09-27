#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> a(20);

    for(int i=0;i<20;i++){
        scanf("%d",&a[i]);
    }

    reverse(a.begin(),a.end());

    for(int i=0;i<20;i++){
        printf("N[%d] = %d\n",i,a[i]);
    }
    return 0;
}
