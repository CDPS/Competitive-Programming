#include <bits/stdc++.h>

using namespace std;


int main(){

    int t=0;
    double p=0.0;

    while(true){

           if(t==2)
            break;


        double a;
        cin >> a;


        if(a>=0.0 && a<=10.0){
            t++;
            p+=a;
        }
        else{
            printf("nota invalida\n");
        }
    }

    printf("media = %.2lf\n",p/2.0);
    return 0;
}
