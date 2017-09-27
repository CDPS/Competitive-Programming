#include <bits/stdc++.h>

using namespace std;


int main(){


    int t,caseno=1;

    scanf("%d",&t);
    char c;
    scanf("%c",&c);

    while(t--){

        string a;
        c ='a';
        while(c!='\n'){
            scanf("%c",&c);
            if(c!=' ' &&c!='\n')
                a+=tolower(c);
        }

        string b;
        c ='a';
        while(c!='\n'){
            scanf("%c",&c);
            if(c!=' ' && c!='\n')
                b+=tolower(c);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        if(a.size()!=b.size()){
            printf("Case %d: No\n",caseno++);
        }
        else{
            int f=1;
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]){
                    f=0;
                    break;
                }
            }

            if(f)
                printf("Case %d: Yes\n",caseno++);
            else
                printf("Case %d: No\n",caseno++);
        }
    }
    return 0;
}
