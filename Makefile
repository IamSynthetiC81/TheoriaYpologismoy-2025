# Configurations
OUT_DIR = out
TEST_DIR = test
HELPER_DIR = HelperFiles
HELPER_FILES = $(HELPER_DIR)/cgen.c

CC = gcc
FLEX = flex
BISON = bison

CFLAGS = -g -Wall -Wextra -I$(OUT_DIR) -I$(HELPER_DIR) -DYYDEBUG=1 -Wno-unused-function
FLEXFLAGS = --header-file=$(OUT_DIR)/lex.yy.h
BISONFLAGS = -d -v -r all -Wcounterexamples --defines=$(OUT_DIR)/myanalyzer.tab.h
LDFLAGS = -lm

# File targets
LEX_OUT = $(OUT_DIR)/lex.yy.c
BISON_OUT = $(OUT_DIR)/myanalyzer.tab.c
EXECUTABLE = $(OUT_DIR)/mycompiler

# Create output directory
$(shell mkdir -p $(OUT_DIR))
.PHONY: all clean test lexer_test run debug run_compiled bison_test

all: $(EXECUTABLE)

$(EXECUTABLE): $(LEX_OUT) $(BISON_OUT) $(HELPER_FILES)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

$(LEX_OUT): mylexer.l $(OUT_DIR)/myanalyzer.tab.h
	$(FLEX) -o $@ $(FLEXFLAGS) $<

$(BISON_OUT): myanalyzer.y
	$(BISON) -o $@ $(BISONFLAGS) $<

$(OUT_DIR)/myanalyzer.tab.h: myanalyzer.y
	$(BISON) -o $(OUT_DIR)/myanalyzer.tab.c $(BISONFLAGS) $<

# run: $(EXECUTABLE)
# 	@./$(EXECUTABLE) < example.la

bison_test: $(EXECUTABLE)
	@echo "Running bison tests..."
	@mkdir -p $(OUT_DIR)/bison_tests
	@for test in $(TEST_DIR)/*.la; do \
		test_name=$$(basename $$test .la); \
		echo "Testing $$test_name..."; \
		./$(EXECUTABLE) < $$test > $(OUT_DIR)/bison_tests/$$test_name.c 2> $(OUT_DIR)/bison_tests/$$test_name.log; \
		if [ $$? -eq 0 ]; then \
			echo "  ✓ Success"; \
		else \
			echo "  ✗ Failed (see $(OUT_DIR)/bison_tests/$$test_name.log)"; \
		fi; \
	done
	@echo "Test results saved to $(OUT_DIR)/bison_tests/"

lexer_test: $(LEX_OUT) $(OUT_DIR)/lexer_stubs.o
	@echo "Running lexer-only tests..."
	@mkdir -p $(OUT_DIR)/lexer_tests
	@$(CC) -o $(OUT_DIR)/lexer_test $(CFLAGS) -DTTLEXER $(LEX_OUT) $(OUT_DIR)/lexer_stubs.o $(HELPER_DIR)/lexer_test.c $(LDFLAGS)
	@for test in $(TEST_DIR)/*.la; do \
		test_name=$$(basename $$test .la); \
		echo "Testing $$test_name (lexer only)..."; \
		./$(OUT_DIR)/lexer_test $$test > $(OUT_DIR)/lexer_tests/$$test_name.tokens 2> $(OUT_DIR)/lexer_tests/$$test_name.log; \
		if [ $$? -eq 0 ]; then \
			echo "  ✓ Success"; \
		else \
			echo "  ✗ Failed (see $(OUT_DIR)/lexer_tests/$$test_name.log)"; \
		fi; \
	done
	@echo "Lexer test results saved to $(OUT_DIR)/lexer_tests/"

$(OUT_DIR)/lexer_stubs.o: HelperFiles/lexer_stubs.c
	$(CC) -c $(CFLAGS) $< -o $@

test: bison_test lexer_test
	@if [ -d $(OUT_DIR)/bison_tests ] && [ -d $(OUT_DIR)/lexer_tests ]; then \
		echo "All tests completed successfully."; \
	else \
		echo "Some tests failed. Check the logs in $(OUT_DIR)/bison_tests and $(OUT_DIR)/lexer_tests."; \
	fi

debug: $(EXECUTABLE)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXECUTABLE) < example.la

run: 
	@mkdir -p $(OUT_DIR)/comp
	@for cfile in $(OUT_DIR)/bison_tests/*.c; do \
		exe_file="$(OUT_DIR)/comp/$$(basename $$cfile .c)"; \
		echo "Compiling $$cfile..."; \
		$(CC) -IHelperFiles -o $$exe_file $$cfile; \
		if [ $$? -eq 0 ]; then \
			echo "Running $$exe_file:"; \
			$$exe_file; \
			if [ $$? -eq 0 ]; then \
				echo "  \n✓ Execution successful"; \
			else \
				echo "  \n✗ Execution failed"; \
			fi; \
		else \
			echo "Compilation failed for $$cfile"; \
		fi; \
	done



clean:
	@rm -rf $(OUT_DIR)
	@rm -f *.output *.tab.* *.yy.*
	@echo "Clean complete"