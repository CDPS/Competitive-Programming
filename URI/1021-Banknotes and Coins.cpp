#include <bits/stdc++.h>

using namespace std;

int main(){
    double n;

    cin >> n;
    int res[10]={0,0,0,0,0,0,0,0,0,0};
    int b[10]={50,20,10,5,2,50,25,10,5,1};

    if(n!=0.0){

        double np;
        int fp= (int) (modf((double)n,&np )*100);
        int ip = (int) np;


        int a[10]={5,2,1,5,2,50,25,10,5,1};


        int d1 = ip%10;
        ip/=10;

        int d2 = ip%10;
        ip/=10;
        int d3 = ip;


        int i=0;
        while(d2!=0){
            if(d2 >=a[i]){
                d2-=a[i];
                res[i]++;
            }
            else{
                i++;
            }
        }

        i=3;
        while(true){
            if(d1==1){
                fp+=100;
                break;
            }

            if(d1==0)
                break;

            if(d1 >=a[i]){
                d1-=a[i];
                res[i]++;
            }
            else{
                i++;
            }
        }
        printf("NOTAS:\n");
        printf("%d nota(s) de R$ 100.00\n",d3);
        for(int i=0;i< 5;i++){
            printf("%d nota(s) de R$ %d.00\n",res[i],b[i]);
        }


        int d4 = fp/100;
        fp-= d4*100;

        i=5;
        while(fp!=0){
            if(fp >=a[i]){
                fp-=a[i];
                res[i]++;
            }
            else{
                i++;
            }
        }

        printf("MOEDAS:\n");
        printf("%d moeda(s) de R$ 1.00\n",d4);
        for(int i=5;i<10;i++){
            if(b[i]<10){
                printf("%d moeda(s) de R$ 0.0%d\n",res[i],b[i]);
            }else{
                printf("%d moeda(s) de R$ 0.%d\n",res[i],b[i]);
            }

        }
    }else{

        printf("NOTAS:\n");
        printf("%d nota(s) de R$ 100.00\n",0);
        for(int i=0;i< 5;i++){
            printf("%d nota(s) de R$ %d.00\n",res[i],b[i]);
        }
        printf("MOEDAS:\n");
        printf("%d moeda(s) de R$ 1.00\n",0);
        for(int i=5;i<10;i++){
            if(b[i]<10){
                printf("%d moeda(s) de R$ 0.0%d\n",res[i],b[i]);
            }else{
                printf("%d moeda(s) de R$ 0.%d\n",res[i],b[i]);
            }

        }
    }
    return 0;
}
