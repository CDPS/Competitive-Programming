#include <bits/stdc++.h>


using namespace std;

int main(){

    string n;
    while( cin >> n){
        string cents;

        cin >> cents ;

        if(cents=="0")
            cents+="0";

        if(cents.size()==1)
            cents= "0" + cents;



        int j=0;
        string res="";
        for(int i=n.size() -1;i >=0;i--){

            if( (j) %3==0 && j!=0)
                res= ","+res;

            res= n[i]+res;
            j++;
        }

        res+= ".";
        res+= cents;

        cout << "$"+res << "\n";

    }

    return 0;
}
