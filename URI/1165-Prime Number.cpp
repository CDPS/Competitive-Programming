#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        if(n<=2)
            printf("%d eh primo\n",n);
        else{

            bool f=1;
            for(int i=2;i<n;i++){
                if(n%i==0){
                    f=0;
                    break;
                }
            }

            if(f)
                printf("%d eh primo\n",n);
            else
                printf("%d nao eh primo\n",n);

        }
    }
    return 0;
}
