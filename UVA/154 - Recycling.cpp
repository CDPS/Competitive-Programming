#include <bits/stdc++.h>

using namespace std;

map<char, int > mp;

int main(){
    mp['P']=0;mp['G']=1; mp['S']=2;mp['A']=3; mp['N']=4;

    string line;

    while(getline(cin, line) && line!="#"){

        vector< vector< char>  > v;

        int l=0;
        int k;

        while(line[0]!='e'){
            v.push_back( vector<char> (5) );
            k=0;
            for(int i=2;i<line.size();i+=4){
                v[l][ mp[ line[i] ] ]  = line[i-2];
                k++;
            }
            l++;
            getline(cin,line);
        }


        int res=10000;
        int aux;
        int idx=0;

        for(int i=0;i<v.size();i++){
             aux=0;
            for(int j=0;j<v.size();j++){
                    for(int k=0; k< 5; k++){
                        if(v[i][k]!=v[j][k])
                            aux++;
                    }
            }
            if(aux<res){
                res = aux;
                idx= i;
            }

        }
        cout  << idx+1 << "\n";
    }
    return 0;
}
