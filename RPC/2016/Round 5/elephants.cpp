#include <bits/stdc++.h>

using namespace std;


int a[100000];

int main(){

    int t;
    scanf("%d",&t);

    while (t--){

        long m,w;

        scanf("%ld %ld",&m,&w);

        priority_queue<int, vector<int> , greater<int> > pq;
        int aux;

        for(long i=0;i<m;i++){
            scanf("%d",&aux);
            pq.push(aux);
        }

        int res =0;
        long wi=0;

        while(!pq.empty()){
            wi+=pq.top();
            pq.pop();

            if(wi>w)
                break;
            res++;
        }

        printf("%d\n",res);
    }
    return 0;
}
