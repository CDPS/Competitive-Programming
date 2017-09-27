#include <bits/stdc++.h>

using namespace std;


string a[100000];




int main(){

        a[1]="1";
        a[2]="5";
        a[3]="3";
        a[4]="4";
		a[5]="2";
		a[6]="9";
		a[7]="7";
		a[8]="8";
		a[9]="6";
		a[10]="10";
		a[11]="11";
		a[12]="15";
		a[13]="13";
		a[14]="14";
		a[15]="12";
		a[16]="19";
		a[17]="17";
		a[18]="18";
		a[19]="16";
		a[20]="50";
		a[21]="51";
		a[22]="55";
		a[23]="53";
		a[24]="54";
		a[25]="52";
		a[26]="59";
        string line;

    while (getline(cin,line)!=NULL) {


            map <char,string> mp;

			int index=1;

			mp[line[0]]= "1";
			index++;
			string res = "1";
			for(int i=1;i<line.size();i++){
				if(mp.count(line[i])==0){
					string al = a[index];
					res+=al;
					mp[line[i]]=al;
					index++;
				}else{
					res+=mp[line[i]];
				}
			}

			cout << res <<endl;
    }

    return 0;
}
