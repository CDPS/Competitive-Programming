#include <bits/stdc++.h>

using namespace std;


int main(){

    int n1,n2;
    scanf("%d %d",&n1,&n2);

        bool in=0;
    if(n1 >n2)
        in =1;

    if(in){

        if(n2>=97 && n2<=100){
            printf("cheia\n");
        }else if(n2>=0&&n2<=2){
            printf("nova\n");
        }else if(n2>2 && n2 <=96){
            printf("minguante\n");
        }

    }else{

        if(n2>=0 && n2<=2){
            printf("nova\n");
        }
        else if(n2>2&&n2<=96){
            printf("crescente\n");
        }
        else if(n2>=97&&n2<=100){
            printf("cheia\n");
        }
    }



    return 0;
}
