#include <bits/stdc++.h>

using namespace std;

bool isOrdered(vector<int> v){
    for(int i=0;i<v.size()-1;i++)
        if(v[i]>v[i+1])
            return false;
    return true;
}


int main(){
    string line;
    int a;

    while(getline(cin,line)){

        stringstream ss (line); vector<int> v;
        while(ss >> a) v.push_back(a);

        int maxi = -1;

        cout << v[0];
        for(int i=1;i<v.size();i++)
            cout << " " << v[i];
        cout << "\n";

        int sizer=0;

        while(!isOrdered(v) ){
            maxi=-1;
            for(int i=0;i<v.size()-sizer;i++)
                maxi=max(maxi,v[i]);

            int idmaxi=0;
            for(int i=0;i<v.size()-sizer;i++) if(v[i]==maxi){ idmaxi=i;break;}

            if(idmaxi!=v.size()-sizer-1){
                    if(idmaxi!=0)
                        cout << v.size() - idmaxi << " ";
                   reverse(v.begin(),v.begin()+idmaxi+1);

                   if(v[v.size()-sizer-1]!=maxi)
                        cout << 1 + sizer << " ",reverse(v.begin(),v.begin() + v.size()-sizer );
            }
            sizer++;
        }
        cout << 0 << "\n";
    }

    return 0;
}
