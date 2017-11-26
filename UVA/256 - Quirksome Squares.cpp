#include <bits/stdc++.h>

using namespace std;

string ts[3] = {"00","01","81"};
string fs[5] = {"0000","0001","2025","3025","9801"};
string ss[5] =  {"000000","000001","088209","494209","998001"};
string es[9] = {"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"};

string toString(long n){
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    return s;
}

void fillit(string &s,int m){
    int n = s.size();
    for(int i=0 ;i< m-n ;i++)
        s = '0' + s;
}

long calc(string n,int m){
    long a =0;
    long pow10=1;

    for(int i=(m/2)-1;i>=0;i--){
        a = a + ( (n[i]-'0')*pow10 );
        pow10*=10;
    }

    long b =0;
    pow10=1;
    for(int i=m-1;i>=(m/2);i--){
        b= b+ ( (n[i]-'0')*pow10);
        pow10*=10;
    }

    return (a+b)*(a+b);
}

//using  brute force to generate
//the answer before submited
//and respond in  O(1)
int main(){

    int n;
    while(cin >> n){
        if(n==2){
            for(int i=0;i<3;i++)
                cout << ts[i] << "\n";
        }else if(n==4){
            for(int i=0;i<5;i++)
                cout << fs[i] << "\n";
        }else if(n==6){
            for(int i=0;i<5;i++)
                cout << ss[i] << "\n";
        }else{
            for(int i=0;i<9;i++)
                cout << es[i] << "\n";
        }
    }
    return 0;
}
