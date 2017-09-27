#include <bits/stdc++.h>

using namespace std;

//Be careful with observations
//Just think what makes you choose right or left child
//The tree is constructive.

int main(){

    int n,m;

    while( scanf("%d %d",&n,&m) ){

        if(n==1 && m== 1) break;

        double t = double(n)/double(m);

        int  np = 1,  mp=1;
        int  nl= 0,  ml=1;
        int  nr = 1, mr =0;

        while(true){
            if(np ==n && mp==m )break;
            if( t < double(np)/double(mp)){
                nr = np; mr = mp;
                np = nr + nl; mp = mr + ml;
                printf("L");
            }else{
                nl = np; ml = mp;
                np = nr + nl; mp = mr + ml;
                printf("R");
            }
        }
        printf("\n");
    }

    return 0;
}
