#include <bits/stdc++.h>

using namespace std;


int main(){

    int l;

    while(scanf("%d",&l)==1){

        priority_queue<int> pq;
        int vi;
        for(int i=0;i<l;i++){
            scanf("%d",&vi);
            pq.push(vi);
        }

        if(pq.top()<10){
            printf("1\n");
        }else if (pq.top()>=10 && pq.top() <20){
            printf("2\n");
        }else{
            printf("3\n");
        }
    }

    return 0;
}
