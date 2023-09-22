#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    char prev = s[0];
    int acc =1;
    int res =0;

    bool shouldCount = true;

    for(int i=1;i<s.size();i++){

        if(s[i] != prev){
            if(shouldCount)
                res++;
            acc=1;
            prev = s[i];
            shouldCount=true;
        }
        else{
            acc++;
            if(acc==5){
               acc = 0;
               res++;
               prev='z';
               shouldCount = false;
            }
        }
    }
    if(acc > 0)
        res++;

    cout  << res <<"\n";
    return 0;
}
