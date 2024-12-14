#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,d=0,cap=0;
    scanf("%d",&n);
    map <long,int> entro;
    while(n--){
        char s;
        long p;
        scanf(" %c %d",&s,&p);
        if(s=='+'){
            if(d==0){
                cap++;
                entro[p]++;
            }
            else{
                entro[p]++;
                d--;
            }
        }
        if(s=='-'){
            map<long,int>::iterator it;
            it = entro.find(p);
            if(it == entro.end()){
                   cap++;
                   d++;
            }else{
                d++;
            }
        }
    }
    printf("%d\n",cap);
    return 0;
}
