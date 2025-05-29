# Theoria Ypologismou 2025 — Lambda Compiler

## Project Overview

This project implements a source-to-source compiler (transpiler) for the Lambda programming language as specified in the ΠΛΗ 402 - Θεωρία Υπολογισμού course (Spring 2025). The compiler translates Lambda code (.la files) to equivalent C99 code while preserving the original program semantics.

## Key Features
### Language Support
- Variables & Types:
- Primitive types (integer, scalar, str, bool)
- Arrays (static and dynamic)
- Composite types (comp)

### Control Structures:
- Conditionals (if/else/endif)
- Loops (for/in/endfor, while/endwhile)
- Flow control (break, continue)

### Functions:

- User-defined functions with parameters
- Return values
- Recursion support
- Special main() entry point

### Advanced Features:

- Array comprehensions
- Macro definitions (@defmacro)
- Built-in I/O functions

### Compiler Features
- Full lexical analysis with Flex
- Complete syntax analysis with Bison
- Semantic validation
- C99 code generation
- Comprehensive error reporting

## Project Structure
```plaintext
.
├── myanalyzer.y            # Bison parser/translator
├── mylexer.l               # Flex lexical analyzer
├── HelperFiles/
│   ├── lambdalib.h         # Runtime support library
│   ├── cgen.c              # Code generation utilities
|   ├── lexer_test.c        # Lexer test utilities
|   ├── bison_test.c        # Bison test utilities
|   └── lexer_stub.c        # Lexer stub for testing
├── test/                   # Directory for test cases
├── out/                    # Build artifacts
│   ├── bison_tests/        # Generated C code
│   ├── lexer_tests/        # Tokenizer output  
|   ├── comp/               # Compiled test programs 
│   └── memcheck/           # ASan reports
└── Makefile                # Build automation
```

## Getting Started
### Prerequisites
- Linux environment (or WSL on Windows)
- GCC (≥9.0)
- Flex (≥2.6)
- Bison (≥3.0)
- asan (for memory checking)

### Installation
```bash
sudo apt-get update
sudo apt-get install flex bison gcc make asan
```     

### Building the Compiler
```bash
make                # Builds the compiler (out/mycompiler)
make debug          # Builds with debug symbols
make memcheck       # Builds with AddressSanitizer
```

### Usage Examples
#### Basic Compilation
```bash
./out/mycompiler < test/hello.la > out/hello.c
gcc -IHelperFiles -o out/hello out/hello.c
./out/hello
```

#### Testing Framework
```bash
make test           # Runs all test cases
make lexer_test     # Only runs lexical analysis tests
make bison_test     # Only runs parser tests
```
#### Memory Checking
``` bash
make memcheck       # Runs all tests with AddressSanitizer

# View results:
cat out/bison_tests/memcheck/*.asan
```

### Development Guide
#### Adding Test Cases
1. Create new .la file in test/ directory
2. Update test targets in Makefile if needed
3. Run make test to verify

#### Debugging Tips
- Use make debug for debug builds
- Enable Bison debug output with yydebug = 1;
- Check generated .output files for parser conflicts

### Implementation Details
#### Key Components
1. Lexical Analysis:
    - Handles Lambda tokens and macros
    - Skips comments/whitespace
    - Reports lexical errors

2. Syntax Analysis:

    - Validates program structure
    - Builds parse tree
    - Checks type compatibility

3. Code Generation:

    - Maps Lambda types to C equivalents
    - Handles variable scoping
    - Implements control flow translation

## Special Cases
- Macros: Processed during lexical analysis
- Arrays: Converted to C arrays with bounds checking
- Components: Translated to C structs with methods

## Known Limitations
- Limited compile-time type checking
- No optimization passes
- Basic error recovery only

## Future Work
- Add more semantic checks
- Implement compiler optimizations
- Expand standard library
- Add debug information generation

## Contributing
Pull requests are welcome. For major changes, please open an issue first.

## License
MIT

---

**Happy coding!** 🚀
