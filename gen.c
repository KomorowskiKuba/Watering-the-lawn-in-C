#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv){

        FILE *out = argc > 1 ? fopen(argv[1], "w") : stdout;

        if(out == NULL){
         fprintf(stderr,"%s blad nie moge zapisac do pliku %s\n", argv[0], argv[1]);
         return EXIT_FAILURE;
        }

        srand(time(NULL));

        for(int i = 0; i < 3200; i++){

                if(i%80 ==0){
                 fprintf(out, "\n");
                }

                int x = rand()%2;
                if( x == 0){
                 fprintf(out, "#");
                }
                else{
                 fprintf(out, "*");
                }
        }
        fclose(out);

}
