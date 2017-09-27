#include <bits/stdc++.h>

using namespace std;
class Compare {
public:
    bool operator()(int& a, int& b)
    {
       if (a >= b) return true;
        return false;
    }
};

int main(){
    int t,caseno=1;
    scanf("%d",&t);
    int n,p,q,aux;
    while(t--){

        scanf("%d %d %d",&n,&p,&q);
        priority_queue<int, vector<int>, Compare> pq;

        for(int i=0;i<n;i++){
            scanf("%d",&aux);
            pq.push(aux);
        }
        int res=0;

        for(int i=0;i<p;i++){

            aux = pq.top();
            q-=aux;
            if(q<0)break;
            res++;
            if(res==n) break;
            pq.pop();
        }
        printf("Case %d: %d\n",caseno++,res);
    }
    return 0;
}
