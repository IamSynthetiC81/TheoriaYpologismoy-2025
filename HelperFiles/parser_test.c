#include "myanalyzer.tab.h"
#include <stdio.h>
#include <stdlib.h>

extern int yyparse(void);
extern FILE* yyin;  // Add this declaration

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    yyin = input;
    int result = yyparse();
    fclose(input);
    
    return result;
}