#include <bits/stdc++.h>

using namespace std;

int a[4];

int r1,r2,c1,c2,d1,d2;
int a1,a2,a3,a4;

bool isValid(int x){
    return x != a[0] && x != a[1] && x != a[2] && x != a[3];
}

bool isSolution(){
    return a[0]+a[1] == r1 &&
           a[2]+a[3] == r2 &&
           a[0]+a[2] == c1 &&
           a[1]+a[3] == c2 &&
           a[0]+a[3] == d1 &&
           a[1]+a[2] == d2;
}

bool backtrack(int i){

    if(i==4){
        bool res = isSolution();
        if(res) {a1=a[0];a2=a[1];a3=a[2];a4=a[3];}
        return res;
    }

    bool res = false;
    for(int j=1; j<=9 && !res; j++){
        if(isValid(j)){
            a[i] = j;
            res = backtrack(i+1);
            if(!res)
                a[i] = 0;
        }
    }
    return res;
}

int main(){

    cin >> r1 >> r2;
    cin >> c1 >> c2;
    cin >> d1 >> d2;


    bool res = backtrack(0);

    if(res){
        cout << a[0] << " " << a[1] << "\n";
        cout << a[2] << " " << a[3] << "\n";
    }
    else{
        cout << "-1" << "\n";
    }
    return 0;
}
