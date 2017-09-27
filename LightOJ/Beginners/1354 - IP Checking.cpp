#include <bits/stdc++.h>

using namespace std;


string tostring(int n){
    stringstream st;
    st << n;
    return st.str();
}
int main() {


    int t,caseno=1;

    scanf("%d",&t);

    while(t--){

        string a,b;

        cin >> a;
        cin >> b;

        a+='.';
        string res= "";
        for(int i=0;i<b.size();i+=9){

            int aux=0;
            for(int j=0;j<8;j++){
                int c = b[i+j]-'0';
                aux+= c*(1<<7-j);
            }
            res+=tostring(aux);
            res+='.';
        }

        if(a!=res)
            printf("Case %d: No\n",caseno++);
        else
            printf("Case %d: Yes\n",caseno++);

    }
    return 0;
}
