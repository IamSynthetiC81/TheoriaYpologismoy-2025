# Theoria Ypologismou 2025 — Lambda Compiler

This project implements a compiler for the Lambda language (Θέωρια Υπολογισμού 2025), supporting:

- Variable and array declarations
- Assignments and expressions
- Array comprehensions (compact array assignments)
- Control flow: if, for, while, break, continue
- Functions and main program
- Struct-like components
- Macros (defmacro)
- The compiler parses Lambda source files (.la), checks their syntax and generates equivalent C code.

## Project Structure
- myanalyzer.y — Bison grammar (parser and code generator)
- mylexer.l — Flex lexer (tokenizer)
- HelperFiles — Helper C files (code generation, runtime support)
- test — Example Lambda programs for testing
- out/ — Build and output directory (generated files, logs, C code)
## How to Compile
1. Install dependencies (if not already):
```bash
sudo apt-get install flex bison gcc make
```
2. Build the compiler:

```bash
make
```

This generates the executable at out/mycompiler.

## How to Test
Run all parser and lexer tests on the example Lambda files in test:

```bash
make test
```

- Parser output (C code) is saved in out/bison_tests/.
- Lexer output (tokens) is saved in out/lexer_tests/.
- Logs for each test are also saved in these directories.

## How to Run
To compile all generated C files and run them:

```bash
make run
```

- This compiles each generated .c file in out/bison_tests/ and runs the resulting executable.
- Output and status are printed to the terminal.
### Example Usage
1. Add your Lambda code to test/your_example.la.
2. Run the test:
```bash
make bison_test
```
The generated C code will be in out/bison_tests/your_example.c.

3. Compile and run the C code:
```bash
gcc -IHelperFiles -o out/your_example out/bison_tests/your_example.c
./out/your_example
```

## Notes
- The compiler supports array comprehensions as described in the assignment.
- Macros can be defined using @defmacro.
- All generated C code includes lambdalib.h for runtime support.

## Cleaning Up
To remove all generated files:
```bash
make clean
```

## Contact
For questions or issues, contact the project author.

---

**Good luck with your project!**