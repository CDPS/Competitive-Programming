#include <bits/stdc++.h>

using namespace std;

int a[27];
int main(){


    string s;
    cin >> s;
    memset(a,0, sizeof a);

    int res=0;
    for(int i=0;i<s.size() ;i++){
        if(a[ s[i]-'a']==0){res++;a[ s[i]-'a']=1;}
    }

    if(res%2)printf("IGNORE HIM!\n");
    else printf("CHAT WITH HER!\n");

    return 0;
}
