#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    int ans =0;
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])ans++;

    if(ans==0 && n%2)ans=1;
    printf("%s\n",ans==1? "YES":"NO");
    return 0;
}
