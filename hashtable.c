#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib.h"
#include "htable.h"

#define WORD_LEN 256

int main(void){
    htable h = htable_new(100, DOUBLE_H);
    char word[WORD_LEN];
    clock_t start, end;
    
    start = clock();
    while (getword(word, sizeof word, stdin) != EOF){
        htable_insert(h, word);
    }
    htable_print_entire_table(h, stdout);
    htable_free(h);
    end = clock();

    printf("Time: %f\n", (end-start) / (double) CLOCKS_PER_SEC);
    
    return EXIT_SUCCESS;
}
