#include <bits/stdc++.h>

using namespace std;

string m = "ertyuiop[]dfghjkl;'cvbnm,.";
string s = "qwertyuiopasdfghjklzxcvbnm";


int findC(char c){
    for(int i=0;i<m.size();i++)
        if(tolower(c)==m[i])
            return i;
}

int main(){
    string line;

    while(getline(cin,line)){
        for(int i=0;i<line.size();i++){
            if(line[i]!=' ') cout << s[ findC(line[i] )];
            else  cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
