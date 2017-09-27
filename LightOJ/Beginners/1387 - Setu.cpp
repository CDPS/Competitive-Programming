#include <bits/stdc++.h>

using namespace std;


int main(){

    int t,caseno=1;

    cin >> t;

    int n;
    while(t--){

        cin >> n;

        string s;  long long k,acc=0;

        printf("Case %d:\n",caseno++);

        while(n--){

            cin >> s;
            if(s[0]=='d'){
                cin >> k;
                acc+=k;
            }
            else{
                printf("%lld\n",acc);
            }

        }
    }
    return 0;
}
