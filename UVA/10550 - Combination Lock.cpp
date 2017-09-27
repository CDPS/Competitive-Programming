#include <bits/stdc++.h>

using namespace std;

int main(){

    int i,f,s,t;
    while(cin >>i >> f >> s >> t){
        if(i == 0 && f==0 && s==0 && t==0)
            break;
        cout << (720+360) +  (((i-f+40)%40)*9) + (((s-f+40)%40)*9) + (((s-t+40)%40)*9) << "\n";
    }
    return 0;
}
