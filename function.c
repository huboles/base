#include "base.h"

/* enumerate up to base 64 */
static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void printnum(char *bin, int ibase, int obase, int start, int end){

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
            printbin(out,start,end);
            break;
        default:
            printbase(out,obase,start,end);
            break;
    }
}

void printbase(int num, int base, int start, int end){
    int n = 0;
    char *s = malloc(100*sizeof(char));
    while (num > 0){
        s[n++] = digits[num%base];
        num /= base;
    }

    if (end != 0) {
        /* print leading zeroes if needed */
        if (end >= n) {
            while (end-- >= n) printf("0"); 
        /* truncate n if there are too many digits */
        } else {
            n = end;
        }
    }

    /* print in reverse order of magnitude */
    for (int i = n - 1; i >= start; printf("%c",s[i--]))

    while (start-- > 0) printf("0");

    printf("\n");
    return;
}

void printbin(int i, int start, int end){
    unsigned long mask = pow(2,(end != 0) ? end-1 : 63);

    for (int t = (end !=0) ? end : 63; t >= start; t-- ){
        printf("%i",((i & mask) == 0) ? 0 : 1);
        printf("%s",(t % 8 == 0) ? " " : "");
        mask = mask >> 1;
    }

    while (start-- > 0) printf("0");

    printf("\n");
    return;
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
