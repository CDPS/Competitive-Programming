#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>
using namespace std;

int main() {

    int t;
    multimap<int, int > m;
    scanf("%d",&t);

    while(t){

        int n;
        scanf("%d",&n);
            if(n==0){
                printf("0 0\n");
                t--;
                continue;
            }
            for(int i=0;i<=10;i++){
             for(int j=0;j<=10;j++){
                multimap<int,int>::iterator it;

                if(i+j==n){
                    it = m.find(i);

                    if(it != m.end()){

                        pair <multimap<int,int>::iterator, multimap<int,int>::iterator> r;
                        r = m.equal_range(i);

                        for (multimap<int,int>::iterator a=r.first; a!=r.second; a++){
                            int v = a->second;

                            if(v==j){
                                j=11;
                                break;
                            }
                        }
                        if(j==11){
                            break;
                        }else{
                         m.insert ( pair<int,int>(i,j) );
                        printf("%d %d\n",i,j);
                        i=11;
                        break;
                        }
                    }else{
                        m.insert ( pair<int,int>(i,j) );
                        printf("%d %d\n",i,j);
                        i=11;
                        break;
                    }
                }
            }
        }
        t--;
    }
    return 0;
}
