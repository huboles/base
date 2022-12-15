#include "printbin.h"

int main(int argc, char *argv[]){
    char *a = malloc(20*sizeof(char));
    char *b = malloc(20*sizeof(char));
    char *n = malloc(60*sizeof(char));
    char c;
    unsigned long num;
    int bits,base;
    int x = 0;

    while ((c = getopt (argc, argv, "a:b:")) != -1){
        switch (c) {
            /* number base */
            case 'a':
                strcpy(a,optarg);
                x++;
                break;
            /* number bits */
            case 'b':
                strcpy(b,optarg);
                x++;
                break;
        }
    }
    
    if (x != 0 && argc > 1) strcpy(n,argv[optind]);
    if (strcmp(n,"") == 0) scanf("%s",n); 

    if (strcmp(a,"") != 0) {
        base = strtol(a,NULL,10);
    } else {
        base = 10;
    }

    if (strcmp(b,"") != 0) {
        bits = strtol(b,NULL,10);
    } else {
        bits = 64;
    }

    num = strtol(n,NULL,base);

    printbin(num,bits);
    return 0;
}

void printbin(unsigned long i, int n){
    unsigned long mask = pow(2,n-1);

    for (int t = n-1; t >= 0; t-- ){
        printf("%i",((i & mask) == 0) ? 0 : 1);
        printf("%s",(t % 8 == 0) ? " " : "");
        mask = mask >> 1;
    }
    printf("\n");

}

