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

.PHONY: all clean test run debug

all: $(EXECUTABLE)

$(EXECUTABLE): $(LEX_OUT) $(BISON_OUT) $(HELPER_FILES)
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

$(LEX_OUT): mylexer.l
	$(FLEX) -o $@ $(FLEXFLAGS) $<

$(BISON_OUT): myanalyzer.y
	$(BISON) -o $@ $(BISONFLAGS) $<

run: $(EXECUTABLE)
	@./$(EXECUTABLE) < example.la

test: $(EXECUTABLE)
	@echo "Running tests..."
	@mkdir -p $(OUT_DIR)/tests
	@for test in $(TEST_DIR)/*.la; do \
		test_name=$$(basename $$test .la); \
		echo "Testing $$test_name..."; \
		./$(EXECUTABLE) < $$test > $(OUT_DIR)/tests/$$test_name.c 2> $(OUT_DIR)/tests/$$test_name.log; \
		if [ $$? -eq 0 ]; then \
			echo "  ✓ Success"; \
		else \
			echo "  ✗ Failed (see $(OUT_DIR)/tests/$$test_name.log)"; \
		fi; \
	done
	@echo "Test results saved to $(OUT_DIR)/tests/"

debug: $(EXECUTABLE)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXECUTABLE) < example.la

clean:
	@rm -rf $(OUT_DIR)
	@rm -f *.output *.tab.* *.yy.*
	@echo "Clean complete"