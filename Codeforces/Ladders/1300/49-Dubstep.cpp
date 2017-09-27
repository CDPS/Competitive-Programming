#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    vector<string> h;
    vector<int> v(s.size(),0);

    for(int i=2;i<s.size();i++){
        if(s[i-2]=='W' && s[i-1]=='U' && s[i]=='B'){
            v[i-2]=v[i-1]=v[i]=1;
        }
    }

    for(int i=0;i<s.size();i++){
        if(v[i]==0){
            string si="";while(v[i]==0 && i<s.size()){ si+=s[i];i++;}
            h.push_back(si);
        }
    }


    for(int i=0;i<h.size()-1;i++)
        cout << h[i] << " ";
    cout << h[h.size()-1] << "\n";
    return 0;
}
