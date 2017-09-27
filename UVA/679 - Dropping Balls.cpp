#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,d,l;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&d,&l);

        int m= (1 << (d-1)) -1, node = 1;

        while(node <= m ){
            if(l%2){
                l= (l/2) +1;
                node = node *2;
            }else{
                l = (l/2);
                node = node*2 +1;
            }
        }
        printf("%d\n",node);
    }
    return 0;
}
