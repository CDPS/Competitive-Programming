#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int h=-1,e=-1,l1=-1,l2=-1,o=-1;

    for(int i=0;i<s.size();i++){

            if(s[i]=='h' && h==-1)
                h=i;
            if(s[i]=='e' && e==-1 &&  h!=-1 && i > h)
                e=i;
            if(s[i]=='l' && l1==-1 && e!=-1 && i>e)
                l1=i;
            if(s[i]=='l' && l2==-1 && l1!=-1 && i > l1)
                l2=i;
            if(s[i]=='o' && o==-1 && l2!=-1 &&i>l2 )
                o=i;
    }

    if( h!=-1 && e>h && l1 >e && l2 >l1 && o > l2)printf("YES\n");
    else printf("NO\n");

    return 0;
}
