%{
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "cgen.h"

#define COMP_SIZE 100
#define COMP_NAME_SIZE 40
#define COMP_FUNCTION_SIZE 1000
#define num_of_all_comp_functions 1000
#define num_of_all_comp_decl 1000

extern int yylex(void);
extern int line_num;
char comps[COMP_SIZE][COMP_NAME_SIZE];
char comp_functions[COMP_SIZE][COMP_FUNCTION_SIZE]; 
char functionName[num_of_all_comp_functions][40];
char DeclName[num_of_all_comp_decl][40];
char DeclType[num_of_all_comp_decl][40];
int decl=0;
char* comp_name;
int numberOfComps=0;
int numberOfCompFunctions=0;
int numberOfDeclaredComps=0;
int tempf, tempd=0;
int counter=0;
char* func_body;
char* conststructtor;



/*char* func_with_body;
char* comp_type;
int func_with_body_size;*/
%}

%union
{
	char* str;
}

%token KW_INTEGER      
%token KW_SCALAR       
%token KW_STR          
%token KW_BOOLEAN      
%token KW_TRUE         
%token KW_FALSE        
%token KW_CONST        
%token KW_IF           
%token KW_ELSE         
%token KW_ENDIF        
%token KW_FOR          
%token KW_IN           
%token KW_ENDFOR       
%token KW_WHILE        
%token KW_ENDWHILE     
%token KW_BREAK        
%token KW_CONTINUE     
%token KW_NOT          
%token KW_AND          
%token KW_OR           
%token KW_DEF          
%token KW_MAIN         
%token KW_RETURN       
%token KW_ENDDEF       
%token KW_COMP         
%token KW_ENDCOMP      
%token <str> IDENTIFIER      
%token <str> CONST_INT       
%token <str> CONST_SCALAR    
%token <str> CONST_STRING    


%token PLUS_OP         
%token MINUS_OP        
%token MULTIPLY_OP     
%token DIVIDE_OP       
%token MODULO_OP       
%token POWER_OP        
%token EQ_SIGN         
%token NOTEQ_SIGN      
%token LT_SIGN         
%token LTEQ_SIGN       
%token GT_SIGN         
%token GTEQ_SIGN       
%token ASSIGN          
%token COMMA           
%token LBRACKET        
%token RBRACKET        
%token DECLARE         
%token ACCESS             
%token SEMICOLON       
%token LPARENTHESIS    
%token RPARENTHESIS
%token HASHTAG
%token LARROW
%token PLUS_ASSIGN
%token MINUS_ASSIGN
%token MULTIPLY_ASSIGN
%token DIVIDE_ASSIGN
%token MODULO_ASSIGN
%token END_OF_FILE   

%start begin


%type <str> programm
%type <str> main body
%type <str> if_statement for_loop while_loop
%type <str> comp_if_statement comp_for_loop comp_while_loop
%type <str> loop comp_loop loop_body comp_loop_body
%type <str> external_declaration
%type <str> IDs ARRAYIDs POINTERIDs
%type <str> var_type comp_var_type
%type <str> var_declaration function_declaration args function_decl_arguments
%type <str> comp comp_variable_declaration comp_function_declaration plus_arguments comp_function_arguments compbody
%type <str> compIDs compARRAYIDs compPOINTERIDs
%type <str> operation 
%type <str> ID_access 
%type <str> equation 
%type <str> function_call function_arguments


%right  ASSIGN
%left   KW_OR
%left   KW_AND
%right  KW_NOT
%left   EQ_SIGN NOTEQ_SIGN
%left   LT_SIGN LTEQ_SIGN GT_SIGN GTEQ_SIGN
%left   PLUS_OP MINUS_OP
%left   MULTIPLY_OP DIVIDE_OP MODULO_OP
%right  NEGATIVE
%right  POWER_OP
%left   ACCESS 

%%

begin:
programm main
    {
        if (yyerror_count == 0) {
            puts(c_prologue);
            printf("%s\n%s",  $1, $2); 
        }
    }
    
|main
    {
        if (yyerror_count == 0) {
            puts(c_prologue);
            printf("%s", $1); 
        }
    }
;
    
programm:
external_declaration { $$ = $1; }
| programm external_declaration { $$ = template("%s\n%s;", $1, $2); }
;

main: 
KW_DEF KW_MAIN LPARENTHESIS RPARENTHESIS DECLARE body KW_ENDDEF SEMICOLON  {$$ = template("int main(){\n%s\n}", $6); }
;

external_declaration:
var_declaration SEMICOLON
| function_declaration SEMICOLON { $$ = $1; }
;

body:
/*empty*/ { $$ = ""; }
| body var_declaration SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| body equation SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| body operation SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| body KW_RETURN operation SEMICOLON { $$ = template("%s\nreturn %s;", $1, $3); }
| body KW_RETURN SEMICOLON { $$ = template("%s\nreturn;", $1); }
| body loop { $$ = template("%s\n%s;", $1, $2); }
;

IDs:
IDENTIFIER { $$ = $1; }
| IDs COMMA IDENTIFIER { $$ = template("%s, %s", $1, $3); }
;

ARRAYIDs:
IDENTIFIER LBRACKET operation RBRACKET { $$ = template("%s[%s]", $1, $3);}
| ARRAYIDs COMMA IDENTIFIER LBRACKET operation RBRACKET { $$ = template("%s, %s[%s]", $1, $3, $5); }
;

POINTERIDs:
IDENTIFIER LBRACKET RBRACKET { $$ = $1; }
| POINTERIDs COMMA IDENTIFIER LBRACKET RBRACKET { $$ = template("%s, %s", $1, $3); }
;

var_type:
KW_INTEGER {conststructtor=""; $$ = template("int"); }
| KW_SCALAR  {conststructtor="";  $$ = template("double"); }
| KW_STR     {conststructtor="";  $$ = template("char*"); }
| KW_BOOLEAN {conststructtor="";  $$ = template("int"); }
| IDENTIFIER {    
                int counter;
                for(counter=0;counter<numberOfComps;counter++){
                    if(strcmp($1, comps[counter])==0){
                        break;
                    }
                }
                if(counter==numberOfComps){
                    printf("ERROR: undeclared struct identifier in line %d", line_num);
                    decl=0;
                    return -1;
                }
                conststructtor=(char*)malloc(50);
                strcat(conststructtor, "= ctor_"); 
                strcat(conststructtor, comps[counter]);
                $$ = $1; 
            }
;

var_declaration:
IDs DECLARE var_type { $$ = template("%s %s%s", $3, $1, conststructtor); }          
| ARRAYIDs DECLARE var_type { $$ = template("%s %s", $3, $1); } 
| POINTERIDs DECLARE var_type { $$ = template("%s* %s", $3, $1); }        
| KW_CONST IDs ASSIGN operation DECLARE var_type { $$ = template("const %s %s=%s", $6, $2, $4); }    
| KW_CONST ARRAYIDs ASSIGN operation DECLARE var_type { $$ = template("const %s %s=%s", $6, $2, $4); } 
| KW_CONST POINTERIDs ASSIGN operation DECLARE var_type { $$ = template("const %s* %s=%s", $6, $2, $4); }
| KW_COMP IDENTIFIER DECLARE comp KW_ENDCOMP  { 
                                                numberOfComps++; 
                                                strcpy(comps[numberOfComps-1], $2);
                                                char* fncts=(char*)malloc(0);
                                                counter=tempf;
                                                for(;counter<numberOfCompFunctions;counter++){
                                                    fncts = (char*)realloc(fncts, strlen(fncts)+COMP_FUNCTION_SIZE);
                                                    strcat(fncts, comp_functions[counter]);
                                                }
                                                fncts = (char*)realloc(fncts, strlen(fncts)+200);
                                                strcat(fncts, "const ");
                                                strcat(fncts, $2);
                                                strcat(fncts, " ctor_");
                                                strcat(fncts, $2);
                                                strcat(fncts, " = { ");
                                                int temp = counter;
                                                counter=tempf;
                                                counter=tempf;
                                                tempf=temp;
                                                if(counter<numberOfCompFunctions){
                                                    strcat(fncts, ".");
                                                    strcat(fncts, functionName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, functionName[counter]);
                                                    counter++;
                                                }
                                                else if(counter<numberOfDeclaredComps){
                                                    strcat(fncts, ".");
                                                    strcat(fncts, DeclName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, "ctor_");
                                                    strcat(fncts, DeclType[counter]);
                                                    counter++;
                                                }
                                                for(;counter<numberOfCompFunctions;counter++){
                                                    strcat(fncts, ", ");
                                                    strcat(fncts, ".");
                                                    strcat(fncts, functionName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, functionName[counter]);
                                                }
                                                counter=tempd;
                                                for(;counter<numberOfDeclaredComps;counter++){
                                                    strcat(fncts, ", ");
                                                    strcat(fncts, ".");
                                                    strcat(fncts, DeclName[counter]);
                                                    strcat(fncts, "=");
                                                    strcat(fncts, "ctor_");
                                                    strcat(fncts, DeclType[counter]);
                                                }
                                                tempd=counter;
                                                strcat(fncts, "};\n#undef SELF");
                                                numberOfComps++;
                                                strcpy(comps[numberOfComps-1], $2);
                                      $$ =template("#define SELF struct %s *self\ntypedef struct %s {\n%s\n}%s;\n%s", $2, $2, $4, $2, fncts); }

;

function_declaration:
KW_DEF IDENTIFIER LPARENTHESIS args RPARENTHESIS LARROW var_type DECLARE body KW_ENDDEF  
                                                    { $$ = template("%s %s (%s) { %s }", $7, $2, $4, $9); }
| KW_DEF IDENTIFIER LPARENTHESIS  args RPARENTHESIS DECLARE body KW_ENDDEF
                                                    { $$ = template("void %s (%s) { %s }", $2, $4, $7);}
;

comp:
comp_variable_declaration SEMICOLON { $$ = template("%s;", $1); }  
| comp_function_declaration SEMICOLON { $$ = template("%s;", $1); }
| comp comp_variable_declaration SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| comp comp_function_declaration SEMICOLON { $$ = template("%s\n%s;", $1, $2); }

;

comp_variable_declaration:
compIDs DECLARE comp_var_type {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], $1);} $$ = template("%s %s", $3, $1); }          
| compARRAYIDs DECLARE comp_var_type {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], $1);} $$ = template("%s %s", $3, $1); } 
| compPOINTERIDs DECLARE comp_var_type {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], $1);} $$ = template("%s* %s", $3, $1); }        
| KW_CONST compIDs ASSIGN operation DECLARE comp_var_type {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], $2);}
                                                             $$ = template("const %s %s=%s", $6, $2, $4); }    
| KW_CONST compARRAYIDs ASSIGN operation DECLARE comp_var_type {if(decl){
                                                                strcpy(DeclName[numberOfDeclaredComps-1],$2);
                                                                }
                                                                $$ = template("const %s %s=%s", $6, $2, $4); } 
| KW_CONST compPOINTERIDs ASSIGN operation DECLARE comp_var_type {if(decl){strcpy(DeclName[numberOfDeclaredComps-1], $2);}
                                                             $$ = template("const %s* %s=%s", $6, $2, $4); }
| IDs DECLARE var_type { $$ = template("%s %s", $3, $1); }  
;

compIDs:
HASHTAG IDENTIFIER { $$ = template("%s", $2); }
| compIDs COMMA HASHTAG IDENTIFIER { $$ = template("%s, %s", $1, $4); }
;

compARRAYIDs:
HASHTAG IDENTIFIER LBRACKET operation RBRACKET { $$ = template("%s[%s]", $2, $4);}
| compARRAYIDs COMMA HASHTAG IDENTIFIER LBRACKET operation RBRACKET { $$ = template("%s, %s[%s]", $1, $4, $6); }
;

compPOINTERIDs:
HASHTAG IDENTIFIER LBRACKET RBRACKET { $$ = template("%s", $2); }
| compPOINTERIDs COMMA HASHTAG IDENTIFIER LBRACKET RBRACKET { $$ = template("%s, %s", $1, $4); }
;

comp_function_declaration:
KW_DEF IDENTIFIER LPARENTHESIS plus_arguments RPARENTHESIS LARROW var_type DECLARE compbody KW_ENDDEF{   
                                                        numberOfCompFunctions++;
                                                        strcpy(comp_functions[numberOfCompFunctions-1], "");
                                                        strcat(comp_functions[numberOfCompFunctions-1], $7);
                                                        strcat(comp_functions[numberOfCompFunctions-1], " ");
                                                        strcat(comp_functions[numberOfCompFunctions-1], $2);
                                                        strcat(comp_functions[numberOfCompFunctions-1], " (SELF");
                                                        strcat(comp_functions[numberOfCompFunctions-1], $4);
                                                        strcat(comp_functions[numberOfCompFunctions-1], ") {");
                                                        strcat(comp_functions[numberOfCompFunctions-1], $9);
                                                        strcat(comp_functions[numberOfCompFunctions-1], "\n}\n");
                                                        strcpy(functionName[numberOfCompFunctions-1], $2);
                                                        $$ = template("%s (*%s) (SELF%s)", $7, $2, $4); }
                                                        
| KW_DEF IDENTIFIER LPARENTHESIS plus_arguments RPARENTHESIS DECLARE compbody KW_ENDDEF{ 
                                                        numberOfCompFunctions++;
                                                        strcpy(comp_functions[numberOfCompFunctions-1], "");
                                                        strcat(comp_functions[numberOfCompFunctions-1], "void ");
                                                        strcat(comp_functions[numberOfCompFunctions-1], $2);
                                                        strcat(comp_functions[numberOfCompFunctions-1], " (SELF");
                                                        strcat(comp_functions[numberOfCompFunctions-1], $4);
                                                        strcat(comp_functions[numberOfCompFunctions-1], ") {");
                                                        strcat(comp_functions[numberOfCompFunctions-1], $7);
                                                        strcat(comp_functions[numberOfCompFunctions-1], "\n}\n");
                                                        strcpy(functionName[numberOfCompFunctions-1], $2);
                                                        $$ = template("void (*%s) (SELF%s)", $2, $4);}

;

compbody:
/*empty*/ { $$ = ""; }
| compbody comp_variable_declaration SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| compbody equation SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| compbody operation SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| compbody KW_RETURN operation SEMICOLON { $$ = template("%s\nreturn %s;", $1, $3); }
| compbody KW_RETURN SEMICOLON { $$ = template("%s\nreturn;", $1); }
| compbody comp_loop     { $$ = template("%s\n%s;", $1, $2); }
;

plus_arguments:
/*empty*/ { $$ = ""; }
| comp_function_arguments { $$ = template(", %s", $1); }
;

comp_function_arguments:
 IDENTIFIER DECLARE var_type { $$ = template("%s %s", $3, $1); }
| comp_function_arguments COMMA IDENTIFIER DECLARE var_type { $$ = template("%s, %s %s", $1, $5, $3); }
;

args:
/*empty*/ { $$ = ""; }
| function_decl_arguments { $$ = template(", %s", $1); }
;

function_decl_arguments:
var_declaration { $$ = template("%s", $1); }
| function_decl_arguments COMMA var_declaration { $$ = template("%s, %s", $1, $3); }
;

function_arguments:
/*empty*/ { $$ = ""; }
|operation { $$ = $1; }
| function_arguments COMMA operation { $$ = template("%s, %s", $1, $3); }
;

function_call: 
IDENTIFIER LPARENTHESIS function_arguments RPARENTHESIS { $$ = template("%s(%s)", $1, $3); }
;

operation:
ID_access { $$ = $1; }
| CONST_INT { $$ = $1; }
| CONST_SCALAR { $$ = $1; }
| function_call { $$ = $1; }
| KW_TRUE { $$ = "1"; }        
| KW_FALSE { $$ = "0"; }
| CONST_STRING {$$ = $1;}
| LPARENTHESIS operation RPARENTHESIS %prec ACCESS { $$ = template("(%s)", $2); }
| LBRACKET operation RBRACKET %prec ACCESS { $$ = template("[%s]", $2); }
| operation POWER_OP operation { $$ = template("pow(%s,%s)", $1, $3); }
| PLUS_OP operation %prec NEGATIVE  { $$ = template("+%s", $2); }
| MINUS_OP operation %prec NEGATIVE { $$ = template("-%s", $2); }
| operation MULTIPLY_OP operation { $$ = template("%s*%s", $1, $3); }
| operation DIVIDE_OP operation { $$ = template("%s/%s", $1, $3); }
| operation MODULO_OP operation { $$ = template("%s%%%s", $1, $3); }
| operation PLUS_OP operation { $$ = template("%s+%s", $1, $3); }
| operation MINUS_OP operation { $$ = template("%s-%s", $1, $3); }
| operation EQ_SIGN operation { $$ = template("%s == %s", $1, $3); }
| operation NOTEQ_SIGN operation { $$ = template("%s != %s", $1, $3); }
| operation LT_SIGN operation { $$ = template("%s < %s", $1, $3); }
| operation LTEQ_SIGN operation { $$ = template("%s <= %s", $1, $3); }
| operation GT_SIGN operation { $$ = template("%s > %s", $1, $3); }
| operation GTEQ_SIGN operation { $$ = template("%s >= %s", $1, $3); }
| operation KW_OR operation { $$ = template("%s || %s", $1, $3); }
| operation KW_AND operation{ $$ = template("%s && %s", $1, $3); }
| KW_NOT operation { $$ = template("!%s", $2); }
;

ID_access:
IDENTIFIER { $$ = $1; }
| IDENTIFIER LBRACKET operation RBRACKET { $$ = template("%s[%s]", $1, $3); }
| IDENTIFIER ACCESS IDENTIFIER { $$ = template("%s.%s", $1, $3); }
| IDENTIFIER ACCESS HASHTAG IDENTIFIER { $$ = template("%s.%s", $1, $4); }
| IDENTIFIER ACCESS function_call { $$ = template("%s.%s", $1, $3); }
| HASHTAG IDENTIFIER { $$ = template("self->%s", $2); }
| HASHTAG IDENTIFIER LBRACKET operation RBRACKET { $$ = template("self->%s[%s]", $2, $4); }
| ID_access ACCESS IDENTIFIER { $$ = template("%s.%s", $1, $3); }
| ID_access ACCESS HASHTAG IDENTIFIER { $$ = template("%s.%s", $1, $4); }
| ID_access ACCESS IDENTIFIER LPARENTHESIS function_arguments RPARENTHESIS {
                                                                            char* com=(char*)malloc(2);
                                                                            if(strcmp($5,"")!=0){
                                                                                strcpy(com, ",");
                                                                            }
                                                                            char* ID_access_func=(char*)malloc(300);
                                                                            char* next=(char*)malloc(300);
                                                                            strcpy(ID_access_func, $1);
                                                                            strcpy(next, $1);
                                                                            while(strstr(next,".")){
                                                                                strcpy(ID_access_func, next+1);
                                                                            
                                                                            }
                                                                            if(strstr(ID_access_func,"]")){
                                                                            $$ = template("%s.%s(&%s%s %s)", $1, $3, $1, com, $5);
                                                                            }
                                                                            else{
                                                                            $$ = template("%s.%s(%s%s %s)", $1, $3, $1, com, $5);
                                                                            }
                                                                            }
;


equation:
ID_access ASSIGN operation { $$ = template("%s=%s", $1, $3); }
| ID_access PLUS_ASSIGN operation { $$ = template("%s+=%s", $1, $3); }
| ID_access MINUS_ASSIGN operation { $$ = template("%s-=%s", $1, $3); }
| ID_access MULTIPLY_ASSIGN operation { $$ = template("%s*=%s", $1, $3); }
| ID_access DIVIDE_ASSIGN operation { $$ = template("%s/=%s", $1, $3); }
| ID_access MODULO_ASSIGN operation { $$ = template("%s%=%s", $1, $3); }
;


comp_var_type:
KW_INTEGER {decl=0; $$ = template("int"); }
| KW_SCALAR  {decl=0; $$ = template("double"); }
| KW_STR     {decl=0; $$ = template("char*"); }
| KW_BOOLEAN {decl=0; $$ = template("int"); }
| IDENTIFIER {    
                int counter;
                for(counter=0;counter<numberOfComps;counter++){
                    if(strcmp($1, comps[counter])==0){
                        counter=-1;
                        break;
                    }
                }
                if(counter!=-1){
                    printf("ERROR: undeclared struct identifier in line %d", line_num);
                    decl=0;
                    return -1;
                }
                numberOfDeclaredComps++;
                strcpy(DeclType[numberOfDeclaredComps-1], $1);
                decl=1;
                $$ = $1; 
            }
;

loop_body:
/*empty*/ { $$ = ""; }
| loop_body KW_BREAK SEMICOLON      {$$ = template("break;\n");}
| loop_body KW_CONTINUE SEMICOLON   {$$ = template("continue;\n");}
| body var_declaration SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| body equation SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| body operation SEMICOLON { $$ = template("%s\n%s;", $1, $2); }
| body KW_RETURN operation SEMICOLON { $$ = template("%s\nreturn %s;", $1, $3); }
| body KW_RETURN SEMICOLON { $$ = template("%s\nreturn;", $1); }
| loop_body loop { $$ = template("%s\n%s;", $1, $2); }
;

comp_loop_body:
/*empty*/ { $$ = ""; }
| comp_loop_body KW_BREAK SEMICOLON                     {$$ = template("break;\n");}
| comp_loop_body KW_CONTINUE SEMICOLON                  {$$ = template("continue;\n");}
| comp_loop_body comp_variable_declaration SEMICOLON    { $$ = template("%s\n%s;", $1, $2); }
| comp_loop_body equation SEMICOLON                     { $$ = template("%s\n%s;", $1, $2); }
| comp_loop_body operation SEMICOLON                    { $$ = template("%s\n%s;", $1, $2); }
| comp_loop_body KW_RETURN operation SEMICOLON          { $$ = template("%s\nreturn %s;", $1, $3); }
| comp_loop_body KW_RETURN SEMICOLON                    { $$ = template("%s\nreturn;", $1); }
| comp_loop_body comp_loop                              { $$ = template("%s\n%s;", $1, $2); }
;

if_statement:
KW_IF LPARENTHESIS operation RPARENTHESIS DECLARE loop_body KW_ENDIF SEMICOLON
                                    { $$ = template("if (%s){\n%s\n}", $3, $6); }
|KW_IF LPARENTHESIS operation RPARENTHESIS DECLARE loop_body KW_ELSE DECLARE loop_body KW_ENDIF 
                                    { $$ = template("if (%s){\n%s\n} else {\n%s\n}", $3, $6, $9); }
;

comp_if_statement:
KW_IF LPARENTHESIS operation RPARENTHESIS DECLARE comp_loop_body KW_ENDIF SEMICOLON
                                    { $$ = template("if (%s){\n%s\n}", $3, $6); }
|KW_IF LPARENTHESIS operation RPARENTHESIS DECLARE comp_loop_body KW_ELSE DECLARE loop_body KW_ENDIF 
                                    { $$ = template("if (%s){\n%s\n} else {\n%s\n}", $3, $6, $9); }
;

for_loop:
KW_FOR IDENTIFIER KW_IN LBRACKET operation DECLARE operation DECLARE operation RBRACKET DECLARE loop_body KW_ENDFOR SEMICOLON
                                    { $$ = template("for (int %s=%s;%s<%s;%s+=%s){\n%s\n}", $2, $5, $2, $7, $2, $9, $12); }
| KW_FOR IDENTIFIER KW_IN LBRACKET  operation DECLARE operation RBRACKET DECLARE loop_body KW_ENDFOR SEMICOLON
                                    { $$ = template("for (int %s=%s;%s<%s;%s++){\n%s\n}", $2, $5, $2, $7, $2, $10); }
;

comp_for_loop:
KW_FOR IDENTIFIER KW_IN LBRACKET operation DECLARE operation DECLARE operation RBRACKET DECLARE comp_loop_body KW_ENDFOR SEMICOLON
                                    { $$ = template("for (int %s=%s;%s<%s;%s+=%s){\n%s\n}", $2, $5, $2, $7, $2, $9, $12); }
| KW_FOR IDENTIFIER KW_IN LBRACKET  operation DECLARE operation RBRACKET DECLARE comp_loop_body KW_ENDFOR SEMICOLON
                                    { $$ = template("for (int %s=%s;%s<%s;%s++){\n%s\n}", $2, $5, $2, $7, $2, $10); }
;

while_loop:
KW_WHILE LPARENTHESIS operation RPARENTHESIS DECLARE loop_body KW_ENDWHILE SEMICOLON
                                    { $$ = template("while (%s){\n%s\n}", $3, $6); }
;

comp_while_loop:
KW_WHILE LPARENTHESIS operation RPARENTHESIS DECLARE comp_loop_body KW_ENDWHILE SEMICOLON
                                    { $$ = template("while (%s){\n%s\n}", $3, $6); }
;

loop:
if_statement { $$ = $1; }
| for_loop { $$ = $1; }
| while_loop { $$ = $1; }
;

comp_loop:
comp_if_statement { $$ = $1; }
| comp_for_loop { $$ = $1; }
| comp_while_loop { $$ = $1; }
;

%%



int main () {
    
    if ( yyparse() != 0 )
        printf("Rejected!\n");
        
}
