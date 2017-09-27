#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);

    string line,s;
    int c;
    bool first=true;
    while(getline(cin,line)){

        if(!first) cout << "\n";
        first=false;
        s="";
        while(line.size()>0){

            for(int i=0;i<line.size();i++){
                c=0;
                if(line[i]=='!')s+="\n";
                while(i< line.size() && line[i]>='0' && line[i]<='9')
                    c+=line[i]-'0', i++;
                for(int j=0;j<c;j++)
                    s=(line[i]=='b')? s+' ': s+line[i];
            }
            s+="\n";
            getline(cin,line);
        }
        cout << s;
    }
    return 0;
}
