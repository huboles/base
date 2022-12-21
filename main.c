#include "base.h"

void help(void);

int main(int argc, char *argv[]){
    char *l = malloc(20*sizeof(char));
    char *L = malloc(20*sizeof(char));
    char *i = malloc(20*sizeof(char));
    char *o = malloc(20*sizeof(char));
    char *n = malloc(60*sizeof(char));
    char c;
    int ibase,obase,start,end;

    /* print stdin in binary if called alone */
    if (argc == 1) {
        scanf("%s",n);
        printbin(strtol(n, NULL, 10),0,0);
        return 0;
    /* print base 10 number in binary if given with no arguments */
    } else if (argc == 2) {
        printbin(strtol(argv[1],NULL,10),0,0);
        return 0;
    } else {
        while ((c = getopt (argc, argv, "ho:i:l:L:n:")) != -1){
            switch (c) {
                case 'h':
                    help();
                    return 0;
                case 'l':
                    strcpy(l,optarg);
                    break;
                case 'L':
                    strcpy(L,optarg);
                    break;
                case 'i':
                    strcpy(i,optarg);
                    break;
                case 'o':
                    strcpy(o,optarg);
                    break;
                case 'n':
                    strcpy(n,optarg);
                    break;
            }
        }
    }

    /* get number from unassigned argv or stdin if it isnt set already */
    if ((strcmp(n,"") == 0) && argv[optind]) strcpy(n,argv[optind]); 
    if (strcmp(n,"") == 0) scanf("%s",n); 

    if (strcmp(i,"") != 0) {
        ibase = strtol(i,NULL,10);
    } else {
        ibase = 10;
    }

    if (strcmp(o,"") != 0) {
        obase = strtol(o,NULL,10);
    } else {
        obase = 2;
    }

    if (strcmp(l,"") != 0) {
        start = strtol(l,NULL,10);
    } else {
        start = 0;
    }

    if (strcmp(L,"") != 0) {
        end = strtol(l,NULL,10);
    } else {
        end = 0;
    }

    printnum(n,ibase,obase,start,end);
    return 0;
}

void help(void){
    printf("OPTIONS:\n");
    printf("\t-n number to convert (takes stdin if not specified)\n");
    printf("\t-i input base (10 if not specified)\n");
    printf("\t-o output base (2 if not specified)\n");
    printf("\t-l number of digits to print\n");
}

