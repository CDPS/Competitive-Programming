#include <bits/stdc++.h>

using namespace std;


int main(){

    int n;

    while(scanf("%d",&n)==1){


        int o,x;
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;

        bool pb=1;
        bool qb=1;
        bool sb=1;

        while(n--){

            scanf("%d %d",&o,&x);

            if(o==1){
                pq.push(x);
                q.push(x);
                s.push(x);
            }
            else{

                if(pq.top()==x){
                    pq.pop();
                    pb=(pb&&true);

                }else{
                    pb= false;
                    pq.pop();
                }

                if(q.front()==x){
                    q.pop();
                    qb=(qb&&true);
                }
                else{
                    q.pop();
                    qb=false;
                }

                if(s.top()==x){
                    s.pop();
                    sb = (sb&&true);
                }
                else{
                    s.pop();
                    sb=false;
                }
            }

        }


        if( (sb&&qb) || (sb&&pb) || (pb&&qb) || (qb && pb && sb) ){
            printf("not sure\n");
        }
        else if(sb){
            printf("stack\n");
        }
        else if(pb){
            printf("priority queue\n");
        }
        else if(qb){
            printf("queue\n");
        }
        else{
            printf("impossible\n");
        }


    }

    return 0;
}
