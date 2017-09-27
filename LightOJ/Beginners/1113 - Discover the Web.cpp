#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    int t,caseno=1;
    scanf("%d",&t);
    while(t){
        printf("Case %d:\n",caseno++);
        stack<string> f;
        stack<string> b;
        string u = "http://www.lightoj.com/";
        string c;
        string v;
        cin >> c;
        while(c[0]!='Q'){

            if(c[0]=='B'){
                if(!b.empty()){
                    f.push(u);
                    u=b.top();
                    b.pop();
                    cout<<u<<endl;
                }else{
                    printf("Ignored\n");
                }
            }
            if(c[0]=='F'){
                if(!f.empty()){
                    b.push(u);
                    u =f.top();
                    f.pop();
                     cout<<u<<endl;
                }else{
                    printf("Ignored\n");
                }
            }
            if(c[0]=='V'){
                cin >> v;
                b.push(u);
                u= v;
                stack <string> e;
                swap(f,e);
                cout<<u<<endl;
            }
             cin >> c;
        }
        t--;
    }
    return 0;
}
