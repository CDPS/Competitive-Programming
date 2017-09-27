#include <bits/stdc++.h>

using namespace std;


int main(){

    long n,k,ki;
    while(scanf("%d",&n)&&n){

        map< long, long> mp;

        long res =0;

        for(int i=0;i<n;i++){

            scanf("%ld",&k);

            for(int i=0;i<k;i++){
                scanf("%ld",&ki);
                mp[ki]++;
            }

            map<long, long>::iterator first;
            map<long, long>::reverse_iterator last;

            first= mp.begin();


            res-= first->first;
            if( first->second == 1) mp.erase(first->first);
            else mp[ first->first ]--;

            last =mp.rbegin();
            res+=last->first;

            if( last->second ==1 ) mp.erase(last->first);
            else mp[last->first]--;
        }
        printf("%ld\n",res);
    }
    return 0;
}
