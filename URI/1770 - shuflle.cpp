#include <bits/stdc++.h>

using namespace std;



int dur[101];
int playlist[1000];
int main(){



    int m,k;

    while(scanf("%d %d",&m,&k)==2){
        map<int,int> mp;

        for(int i=0;i<m;i++){
            mp[i+1]=1;
            scanf("%d",dur +i);
        }

        for(int i=0;i<k;i++){
            scanf("%d",playlist +i);
        }

        int res=0;
        bool r=0;
        for(int i=0;i<k;i++){
            int ki= playlist[i];


            if(mp.count(ki)){
                mp.erase(ki);
            }
            res+=dur[ki-1];

            if(mp.empty()){
                r=1;
                break;
            }
        }

        if(r)
            printf("%d\n",res);
        else
            printf("-1\n");
    }
    return 0;
}
