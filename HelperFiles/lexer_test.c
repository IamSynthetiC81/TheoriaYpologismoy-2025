#include <stdio.h>
extern int yylex(void);
extern FILE *yyin;
extern char *yytext;

int main(int argc, char **argv) {
	if (argc > 1) {
		yyin = fopen(argv[1], "r");
		if (!yyin) {
			perror("fopen");
			return 1;
		}
	}
	int tok;
	while ((tok = yylex()) != 0) {
		printf("TOKEN: %d\tTEXT: %s\n", tok, yytext);
	}
	if (argc > 1) fclose(yyin);
	return 0;
}