#include <bits/stdc++.h>

using namespace std;

int acc[8];
int n,a;
vector <string> v;

bool calc(){

    while(acc[1]>=1 && acc[2]>=1 && acc[4]>=1){
        acc[1]--;acc[2]--;acc[4]--;
        v.push_back("1 2 4\n");
    }

    while(acc[1]>=1 && acc[2]>=1 && acc[6]>=1){
        acc[1]--;acc[2]--;acc[6]--;
        v.push_back("1 2 6\n");
    }

    while(acc[1]>=1 && acc[3]>=1 && acc[6]>=1){
        acc[1]--;acc[3]--;acc[6]--;
        v.push_back("1 3 6\n");
    }

    for(int i=1;i<=7;i++)
        if(acc[i])
            return 0;
    return 1;
}

int main(){

    memset(acc,0,8);
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a, acc[a]++;

    if(acc[5] || acc[7]){
        cout << "-1\n";
    }else if(calc()){
        for(int i=0;i<v.size();i++)
            cout << v[i];
    }else{
        cout << "-1";
    }
    return 0;
}
