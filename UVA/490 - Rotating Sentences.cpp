#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> v;
    string line;

    int maxL=-1;

    while(getline(cin,line)){
        v.push_back(line), maxL=max(maxL ,(int)line.size());
    }

    for(int i=0;i<maxL;i++){
        for(int j=v.size()-1;j>=0;j--){
            if(v[j].size()>i){
                cout << v[j][i];
            }else{
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
