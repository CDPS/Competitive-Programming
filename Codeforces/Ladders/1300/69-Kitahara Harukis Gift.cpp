#include <bits/stdc++.h>

using namespace std;

int a[2];

int main(){
    int n,aux;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&aux);
        a[(aux/100)-1]++;
    }
    int acc = a[0]*100 + a[1]*200;
    if(acc%200!=0){  printf("NO\n"); return 0; }

    for(int i=0;i<=a[0];i++){
        for(int j=0;j<=a[1];j++){
            if( (i*100 + j*200)==acc/2 ){
                printf("YES\n");return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
