#include <stdio.h>
int main(){

    int t,caseno=1;

    scanf("%d",&t);

    while(t--){

        int f1,c1,f2,c2;
        scanf("%d %d %d %d",&f1,&c1,&f2,&c2);
        int a = f1+c1,b=f2+c2;
        if( (a%2 && b%2) || (a%2==0 && b%2==0)){

                if(c1-c2==0){
                    printf("Case %d: 2\n",caseno++);
                }else{

                    if( ((double)(f2-f1)/(double)(c2-c1))==1.0 || ((double)(f2-f1)/(double)(c2-c1))==-1.0){
                        printf("Case %d: 1\n",caseno++);
                    }else{
                        printf("Case %d: 2\n",caseno++);
                    }
                }
        }
        else{
            printf("Case %d: impossible\n",caseno++);
        }

    }

    return 0;
}
