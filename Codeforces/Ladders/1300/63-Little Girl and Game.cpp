#include <bits/stdc++.h>

using namespace std;


int main(){
    vector <int > c (26,0);
    string s;
    cin >> s;

    for(int i=0;i<s.size();i++)
        c[  s[i]-'a']++;
    int odds=0;

    for(int i=0;i<c.size();i++)if(c[i]%2) odds++;

    if(odds <=1) printf("First\n");
    else if(odds %2) printf("First\n");
    else printf("Second\n");
    return 0;
}
