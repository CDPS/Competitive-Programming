#include <bits/stdc++.h>
using namespace std;

int main(){

    int x,z;
    scanf("%d",&x);

    while(true){
        scanf("%d",&z);

        if(z>x)
            break;
    }

    int res=0;
    int j=0;
    for(int i=x;i<=z;i++){
            res+=i;
            j++;
            if(res>z)
                break;
    }

    printf("%d\n",j);
    return 0;
}
