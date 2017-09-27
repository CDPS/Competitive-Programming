#include <bits/stdc++.h>


using namespace std;


int main(){


    int n,b,t;

    while( scanf("%d %d %d",&n,&b,&t)==3 ){

        int i=0,j=0;
        int resi =0,resj=0;
        bool ib=true,jb=true;
        while(n>0){

            if(n-b>=0 && ib){
                n-=b;
                i+=b;
                resi+=b;
                j--;
            }else{
                if(ib){
                    i+=n;
                    resi+=n;
                    n=0;
                }
            }

            if(n-t>=0 && jb){
                n-=t;
                j+=t;
                resj+=t;
                i--;
            }else{
                if(jb){
                    j+=n;
                    resj+=n;
                    n=0;
                }
            }

            if(i>j){
                i=i-j;
                j=0;
                ib=false;
                jb=true;
                i--;
            }else if(i<j){
                j=j-i;
                i=0;
                ib=true;
                jb=false;
                j--;
            }
            else{
                i=0;
                j=0;
                ib=true;
                jb=true;
            }
        }

        printf("%d %d\n",resi,resj);

    }

    return 0;
}
