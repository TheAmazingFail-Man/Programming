#include <iostream>
 
void hex(unsigned num){
    if ( num ){
        hex(num / 16);
        printf("%c", "0123456789abcdef"[num % 16]);
    }
}
 
int main(void){
    unsigned num;   
    printf("Number: ");
	scanf("%u", &num);
    hex(num);
    printf("\n");
    system("pause");
    return 0;
}
