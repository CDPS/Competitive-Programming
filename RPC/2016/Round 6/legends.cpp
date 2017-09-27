#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    scanf("%d",&t);

    double inf= 100000000000;


    while(t--){

        for(int i=0;i<5;i++){
            string n; long long k; long long d;

            cin >> n >> k >> d;

            if(d==0)
                continue;

            double rat = (double)k/(double)d;

            if(rat < (1/3.0) )
                cout << n << " plz uninstall"<< endl;
        }



        double minn=1000000000.00;

        vector<double> a;
        vector <string> sS;

         for(int i=0;i<5;i++){

            string n; long long k; long long d;
            cin >> n >> k >> d;

            if(d==0)
                continue;

            double rat = (double)k/(double)d;

            sS.push_back(n);
            a.push_back(rat);

            if(rat < minn){
                minn=rat;
            }
        }

        vector<string> s2;

        for(int i=0;i<sS.size();i++){
            if(a[i]==minn)
                s2.push_back(sS[i]);
            else if(a[i] < (1/2.0) ){
                s2.push_back(sS[i] );
            }
        }

        for(int i=0;i<s2.size();i++)
            cout << s2[i]<<" plz uninstall"<< endl;
    }

    return 0;
}
