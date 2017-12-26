#include <bits/stdc++.h>

using namespace std;

bool check(string a){
    for(int i=0;i<a.size();i++)
        if( !(a[i]>='a' && a[i]<='z') )
            return false;
    return a!="";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string line,word;
    set<string> st;

    while(getline(cin,line)){

        transform(line.begin(), line.end(), line.begin(), ::tolower);
        word="";
        for(int i=0;i<line.size();i++){
            if(line[i]>='a' && line[i]<='z'){
                word+=line[i];
            }
            else{
                if(word!="") st.insert(word);
                word="";
            }
        }
        if(check(word)) st.insert(word);
    }

    set<string>::iterator it;
    for(it = st.begin();it!=st.end();it++)
        cout << *it << "\n";
    return 0;
}
