#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d",&n);

    for(int i=1;i<n*4;i+=4){

        for(int j=0;j<3;j++){
            printf("%d ",j+i);
        }
        printf("PUM\n");
    }
    return 0;
}
