#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b,c;

    cin >>a ;
    cin >> b;
    cin >> c;

    if(a=="vertebrado"){
        if(b=="ave"){
                if(c=="onivoro"){
                    printf("pomba\n");
                }else{
                    printf("aguia\n");
                }
        }else{
            if(c=="onivoro"){
                    printf("homem\n");
            }else{
                    printf("vaca\n");
            }
        }
    }else{
        if(b=="inseto"){
            if(c=="hematofago"){
                printf("pulga\n");
            }else{
                printf("lagarta\n");
            }
        }else{
            if(c=="hematofago"){
                printf("sanguessuga\n");
            }else{
                printf("minhoca\n");
            }
        }
    }
    return 0;
}
