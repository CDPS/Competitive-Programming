#include <bits/stdc++.h>

using namespace std;


int main(){


    double s;

    while(true){

        int valid=0;
        double total=0.0;

        while(valid<2){

            scanf("%lf",&s);
            if(s>=0.00 && s<=10.00){
                valid++;
                total+=s;
            }
            else{
                printf("nota invalida\n");
            }
        }

        printf("media = %.2lf\n",total/2.0);

        int x;
        printf("novo calculo (1-sim 2-nao)\n");

        bool t=true;

        while(true){
            scanf("%d",&x);

            if(x<1 || x>2)
            printf("novo calculo (1-sim 2-nao)\n");

            if(x==1)
                break;

            if(x==2){
                t=false;
                break;
            }
        }



        if(t)
            continue;
        else
            break;
    }
    return 0;
}
