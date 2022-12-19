#include "base.h"

/* enumerate up to base 64 */
static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void printnum(char *bin, int ibase, int obase, int len){

    int out = getnum(bin,ibase);

    switch (obase) {
        case (16):
            printf("0x%x\n", out);
            break;
        case (10):
            printf("%i\n", out);
            break;
        case (8):
            printf("%o\n", out);
            break;
        case (2):
            printbin(out,len);
            break;
        default:
            printbase(out,obase);
            break;
    }
}

void printbase(int num, int base){
    int n = 0;
    char *s = malloc(100*sizeof(char));
    while (num > 0){
        s[n++] = digits[num%base];
        num /= base;
    }
    for (int i = n - 1; i >= 0; i--){
        printf("%c",s[i]);
        printf("%s",(i%3==0) ? " " : "");
    }
    printf("\n");
}

void printbin(int i, int n){
    unsigned long mask = pow(2,n-1);

    for (int t = n-1; t >= 0; t-- ){
        printf("%i",((i & mask) == 0) ? 0 : 1);
        printf("%s",(t % 8 == 0) ? " " : "");
        mask = mask >> 1;
    }
    printf("\n");

}

int getnum(char *num, int base){
    int out = 0;
    int j = strlen(num) - 1;

    for (int i = 0; i < strlen(num); i++ ){
        /* get pointer to char in digit index */
        char *c = strchr(digits,num[i]);
        /* gets int by finding offset in pointer values */
        int offset = c - digits;
        int mag = pow(base,j--);
        out += (mag * offset); 
    }
    
    return out;
}
