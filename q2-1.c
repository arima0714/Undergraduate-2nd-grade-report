#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    long   x[100];
    char  *typeStr = argv[1];
    void  *ptr = (void*)strtol(argv[2], NULL, 16);
    int    num = atoi(argv[3]);
    char  *cptr= (char*)x;
    int i;
    for (i=0; i<100*sizeof(long); i++)
        cptr[i] = i + 0x10;


    // example
    /* if (!strcmp(typeStr, "float")) {
        float *ptrnew;
        float value;

        ptrnew = ((float*)ptr) + num;
        value  = *((float*)cptr+num);

        printf("%p 0x%x\n", ptrnew, value);
    }*/

    if (!strcmp(typeStr, "char")) {
        char *ptrnew;
        char value;

        // add your code here
        ptrnew = ((char*)ptr) + num;
        value  = *((char*)cptr+num);

        printf("%p 0x%x\n", ptrnew, value);
    }
    else if (!strcmp(typeStr, "short")) {
        short *ptrnew;
        short value;

        // add your code here
        ptrnew = ((short*)ptr) + num;
        value  = *((short*)cptr+num);

        printf("%p 0x%x\n", ptrnew, value);
    }
    else if (!strcmp(typeStr, "int")) {
        int  *ptrnew;
        int  value;

        // add your code here
        ptrnew = ((int*)ptr) + num;
        value  = *((int*)cptr+num);

        printf("%p 0x%x\n", ptrnew, value);
    }
    else if (!strcmp(typeStr, "long")) {
        long *ptrnew;
        long value;

        // add your code here
        ptrnew = ((long*)ptr) + num;
        value  = *((long*)cptr+num);

        printf("%p 0x%lx\n", ptrnew, value);
    }
    else {
        printf("Undefined type\n");
    }
  
    return 0;
}

