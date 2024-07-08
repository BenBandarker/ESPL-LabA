#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    int debug = 0; // debug mode
    char *encode = ""; // encoder code
    int enccodeSign = 0; // Positive =1 / Negative=-1 / no code =0 
    FILE *inP = stdin;
    FILE *outP = stdout;

    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "+D") == 0)
        {
            debug = 1;
        }
        else if(strcmp(argv[i], "-D") == 0)
        {
            debug = 0;
        }
        if((strcmp(argv[i], "+D") != 0) && debug == 1)
        {
            fprintf(stderr, "%s\n", argv[i]);
        }
        if((argv[i][0] == '-') && (argv[i][1] == 'i'))
        {
            inP = fopen(argv[i] + 2, "r");
            if(inP == NULL)
            {
                fprintf(stderr, "%s\n", "Error! inpot file invalid");
                exit(1);
            }
        }
        if((argv[i][0] == '-') && (argv[i][1] == 'o'))
        {
            //printf("----------\n");
            outP = fopen(argv[i] + 2, "w");
            if(outP == NULL)
            {
                fprintf(stderr, "%s\n", "Error! output file invalid");
                exit(1);
            }
        }
        //if(strcmp(argv[i], "+e") == 0)
        if((argv[i][0] == '+') && (argv[i][1] == 'e'))
        {
            enccodeSign = 1;
            encode = argv[i] + 2;
            //printf(encode);
        }
        else if((argv[i][0] == '-') && (argv[i][1] == 'e'))
        {
            enccodeSign = -1;
            encode = argv[i] + 2;
        }
    }
    int ch; //every char in the Text we want to encode
    int indexCode = 0; // index ofthe char in the encoder code
    //char *chCode;
    while((ch = fgetc(inP)) != EOF)
    {
        //printf("%i --- first\n", ch);
        //printf("while ---");
        if(encode[indexCode] == '\0')
        {
            indexCode = 0;
        }
        int add = enccodeSign * (*&encode[indexCode] - '0');
        //printf("%i ---- ADD\n", add);
        if(ch >= 'a' && ch <= 'z')
        {
            //printf("%i ???????\n", ch +add);
            ch = ((ch + add) % 'a') + 26;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = (((ch + add) % 'A') + 26) ;
        }
        else if(ch >= '0' && ch <='9')
        {
            ch = (((ch + add) % '0') + 10);
        }
        else 
        {
            ch = ch;
        }
        //printf("%i\n", ch);
        fputc(ch, outP);
        indexCode++;
    }
    fclose(inP);
    fclose(outP);
    return 0;
}