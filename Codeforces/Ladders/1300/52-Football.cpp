#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int aux=s[0];
    int coutn =1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=aux){
            coutn=1;
            aux=s[i];
        }else{
            coutn++;
            if(coutn==7){
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
