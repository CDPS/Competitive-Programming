#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string line;
    while(getline(cin,line)){

        if(line == "DONE") break;

        transform(line.begin(), line.end(), line.begin(), ::tolower);
        string a="",b="";

        for(int i=0;i<line.size();i++){
            if(line[i]>='a' && line[i]<='z')
                a = a+ line[i],b = line[i]+b;
        }
        cout << ( (a==b)?"You won't be eaten!" :"Uh oh..") << "\n" ;
    }
    return 0;
}
