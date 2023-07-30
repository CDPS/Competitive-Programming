#include <bits/stdc++.h>

using namespace std;

int e[3] = {0 ,0 ,0 };
string indexes[3] = {"chest","biceps", "back"};

int main(){

    int n,x,index;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;
        e[i%3]+=x;
    }

    index=0;
    for(int i=1;i<3;i++){
        if(e[index] < e[i])
            index = i;
    }

    cout << indexes[index] << "\n";
    return 0;
}
