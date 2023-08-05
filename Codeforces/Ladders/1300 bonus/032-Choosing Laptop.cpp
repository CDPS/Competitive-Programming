#include <bits/stdc++.h>

using namespace std;

struct pc{

    int ram, processor, hdd, cost;
    pc(int a, int b, int c, int d) : ram(a), processor(b) , hdd(c), cost(d){}
    pc(){}
};

pc a[100];

bool obst[100];

int main(){

    int n, ram, processor, hdd, cost;

    cin >> n;

    for(int i=0; i< n; i++){
        cin >> ram >> processor >> hdd >> cost;
        a[i] = pc(ram,processor,hdd, cost);
        obst[i]=false;
    }

    for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
            if(i==j)continue;

            if( a[i].ram < a[j].ram &&
                a[i].processor < a[j].processor &&
                a[i].hdd < a[j].hdd ){
                    obst[i] = true;
                    break;
                }
        }
    }

    int index = -1;
    int tempCost = 100000000;
    for(int i=0; i< n; i++){
        if(!obst[i] && a[i].cost <tempCost ){
            index = i + 1;
            tempCost =  a[i].cost;
        }
    }
    cout << index << "\n";
    return 0;
}
