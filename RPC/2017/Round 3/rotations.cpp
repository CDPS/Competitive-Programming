#include <bits/stdc++.h>

using namespace std;

bool p[32];

int main(){

    unsigned long long n, t;
    scanf("%llu",&t);

    while(t--){

        memset(p, false, sizeof p);

        scanf("%llu",&n);

        for(int i=32;i<36;i++)
             if( ( n & ( 1 << i-32 ) )!=0  )
                    n!=(1<<i);

        long long acc =0;
        set<int> s;

        for(int i = 0; i<32;i++){
            int r = 0,  k= 4;
            for(int j = 0; j < 5; j++){
                if(  ( n & ( 1 << j+i ) )!=0  )
                    r+= (1<<k);
                k--;
            }
            s.insert(r);
        }

        if(s.size()==32)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
