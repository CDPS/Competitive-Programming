#include <bits/stdc++.h>

using namespace std;

int main(){

    int x,y;

    scanf("%d %d",&x,&y);

    for(int i=1;i<=y;i++){

        printf("%d",i);

        for(int j=0;j< x-1 && i<y;j++){
            i++;
            printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
