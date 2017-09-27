#include <bits/stdc++.h>

using namespace std;


int main(){

    int a[3];
    for(int i=0;i<3;i++)
        scanf("%d",i+a);

    sort(a,a + 3);

    printf("%d eh o maior\n",a[2]);
    return 0;
}
