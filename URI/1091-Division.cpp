/*Invertir numero de hasta 10 digitos*/
#include <stdio.h>
int main(void){
/*Definir variable*/
    int n, resto,invertido=0;
/*Lo guarda en la variable n*/
    scanf("%d",&n);
/*El while reccore el numero ingresado*/
    while(n!=0)
      {
/*Guarda el resto de la división del numero y 10,para asi guardar cada dígito */
         resto=n%10;
/*Disminuye el numero para asi poder utilizar el digito siguiente*/
         n=n/10;
/*Invierte el número directamente*/
         invertido=invertido*10+resto;
       }
/*Imprime el número invertido*/
printf("%d \n",invertido);
return 0;
}
