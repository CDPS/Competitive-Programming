#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,caseno=1;

    bool first = true;

    while(true){
        scanf("%d",&n);
        if(n==0)
            break;

        if (!first) {
            printf("\n");
        }
        first = false;

        map<int,int> mp;
        map <int,int>::iterator it;

        int p,c;
        int tp=0,tc=0;

        for(int i=0;i<n;i++){
            scanf("%d %d",&p,&c);
            tp+=p;
            tc+=c;
            int z= c/p;
            mp[z]+=p;
        }


        printf("Cidade# %d:\n",caseno++);


        for(it = mp.begin(); it!=mp.end(); it++) {
            if(it!=mp.begin()) cout << " ";
            printf("%d-%d",it->second,it->first);
        }

        printf("\n");
        double int_part;
        int frac_part= (int) (modf ( (double)tc/tp, &int_part) *100);

        if(frac_part < 10) printf("Consumo medio: %d.0%d m3.\n", (int)int_part, (int)frac_part);
        else printf("Consumo medio: %d.%d m3.\n", (int)int_part, (int)frac_part);


    }
    return 0;
}
