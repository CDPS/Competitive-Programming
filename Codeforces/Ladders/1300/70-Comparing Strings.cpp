#include <bits/stdc++.h>

using namespace std;

int acca[26];
int accb[26];

int main(){
    string a,b;
    cin >> a >> b;
    for(int i=0;i<26;i++)
        acca[i]=accb[i]=0;

    for(int i=0;i<a.size();i++)
        acca[a[i]-'a']++;

    for(int i=0;i<b.size();i++)
        accb[b[i]-'a']++;

    if(a.size()==b.size()){
        for(int i=0;i<26;i++){
            if(acca[i]!=accb[i]){
                cout << "NO";
                return 0;
            }
        }
        int c=0;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i]) c++;
        if(c==2){cout << "YES";return 0;}
    }
    cout << "NO";
    return 0;
}
