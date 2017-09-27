#include <bits/stdc++.h>

using namespace std;

string toString(long n){
    stringstream ss;  string res;
    ss << n;
    ss >> res;
    return res;
}


string factorize(long n){

    if(n==1 || n==0)
        return  toString(n);

    string res="";
    int r1 =1;

    while(n%2==0){
        n/=2;
        if(r1*2>=10){ res+= r1+'0'; r1=2;}
        else{ r1*=2; }
    }
    if(r1!=1)  res+= (r1 +'0');

    int r2 =1;
    while(n%3==0){
        n/=3;
        if(r2*3>=10){ res+= r2+'0'; r2=3;}
        else{ r2*=3; }
    }
     if(r2!=1)  res+= (r2 +'0');

    int r3 =1;
    while(n%5==0){
        n/=5;
        if(r3*5>=10){ res+= r3+'0'; r3=5;}
        else{ r3*=5; }
    }
     if(r3!=1) res+= (r3 +'0') ;

    int r4 =1;
    while(n%7==0){
        n/=7;
        if(r4*7>=10){ res+= r4+'0'; r4=7;}
        else{ r4*=7; }
    }
     if(r4!=1) res+= (r4 +'0') ;


    sort(res.begin(),res.end());
    if(n!=1)
        return "-1";
    else
        return res;
}

string getMin(string s){

    int i=0;
    while( i<s.length() && s[i]-'0'<5 ) i++;

    vector <int> frec(5,0);

    for(int j=0;j<i;j++)
        frec[ s[j]-'0' ]++;

    string lowest8="";

    if(frec[2]>0 && frec[4]>0){
        if(frec[2]< frec[4]){
            for(int j=0;j<frec[2];j++)
                lowest8+="8";
            frec[4]-=frec[2];
            frec[2]=0;
        }else{
             for(int j=0;j<frec[4];j++)
                lowest8+="8";
            frec[2]-=frec[4];
            frec[4]=0;
        }
    }

    string lowest6="";

    if(frec[2]>0 && frec[3]>0){
        if(frec[2]< frec[3]){
            for(int j=0;j<frec[2];j++)
                lowest6+="6";
            frec[3]-=frec[2];
            frec[2]=0;
        }else{
             for(int j=0;j<frec[3];j++)
                lowest6+="6";
            frec[2]-=frec[3];
            frec[3]=0;
        }
    }

    string resto="";
    for(int j=2;j<=4;j++){
        if(frec[j]>0){
            for(int k=0;k<frec[j];k++){
                resto+= (j+ '0');
            }
        }
    }

    if(resto=="" && lowest6 == "" && lowest8 == "")
        return s;
    return resto + lowest6 + lowest8 + s.substr(i);
}
int main(){

    int t;
    scanf("%d",&t);

    long n;
    while(t--){
        scanf("%ld",&n);
        string ans = factorize(n);
        cout << getMin(ans) << "\n";
    }
    return 0;
}


