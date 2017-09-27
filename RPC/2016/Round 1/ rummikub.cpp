#include <bits/stdc++.h>


using namespace std;

int groups[100];



int main(){

    int t;

    scanf("%d",&t);


    while(t--){

        int m;
        scanf("%d",&m);

        bool d=false;

        priority_queue <int, vector<int>, greater<int> > r,y,b,g;

         int v;
        char s;

        while(m--){

          scanf("%d%c ",&v, s);

            groups[v-1]++;

            if(groups[v-1] >=3){
                d= true;
            }

            if(s=='r'){
                r.push(v);
            }

            if(s=='y'){
                y.push(v);
            }

            if(s=='g'){
                g.push(v);
            }

            if(s=='b'){
                b.push(v);
            }

            printf("%d%c ",v,s);
        }

        if(d){

            printf("Yes\n");

        }else{

            int c=1;
            int p = r.top();
            r.pop();

            while(!r.empty()){

                if(r.top()==p+1){
                    c++;
                    p=r.top();
                }
                else{
                    c=1;
                    p=r.top();
                }

                if(c==3){
                    d=true;
                    break;
                }
            }

            if(d){
                printf("Yes\n");
                continue;
            }


            c=1;
            p = y.top();
            y.pop();

            while(!y.empty()){

                if(y.top()==p+1){
                    c++;
                    p=y.top();
                }
                else{
                    c=1;
                    p=y.top();
                }

                if(c==3){
                    d=true;
                    break;
                }
            }

            if(d){
                printf("Yes\n");
                continue;
            }


            c=1;
            p = g.top();
            g.pop();

            while(!g.empty()){

                if(g.top()==p+1){
                    c++;
                    p=g.top();
                }
                else{
                    c=1;
                    p=g.top();
                }

                if(c==3){
                    d=true;
                    break;
                }
            }

            if(d){
                printf("Yes\n");
                continue;
            }

            c=1;
            p = b.top();
            b.pop();

            while(!b.empty()){

                if(b.top()==p+1){
                    c++;
                    p=b.top();
                }
                else{
                    c=1;
                    p=b.top();
                }

                if(c==3){
                    d=true;
                    break;
                }
            }

            if(d){
                printf("Yes\n");
            }
            else{

                 printf("No\n");
            }
        }
    }

    return 0;
}
