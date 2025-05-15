OUT_DIR = out
TEST_DIR = test
TEST_OUT_DIR = out

CC = gcc
FLEX = flex
BISON = bison

CFLAGS = -g -Wall -Wextra -I$(OUT_DIR)
FLEXFLAGS = -l
BISONFLAGS = -d -v
LDFLAGS = -lm

# Create output directory if it doesn't exist
$(shell mkdir -p $(OUT_DIR))
$(shell mkdir -p $(TEST_DIR))



all: mycompiler

mycompiler: mylexer.l myanalyzer.y
	${FLEX} -o ${OUT_DIR}/lex.yy.c ${FLEXFLAGS} mylexer.l
	${BISON} -o ${OUT_DIR}/myanalyzer.tab.c ${BISONFLAGS} myanalyzer.y
	${CC} -o $(OUT_DIR)/mycompiler ${CFLAGS} ${LDFLAGS} ${OUT_DIR}/myanalyzer.tab.c ${OUT_DIR}/lex.yy.c

run: mycompiler
	./mycompiler < example.la

test: mycompiler
	@echo "Running tests..."
	@for test in $(TEST_DIR)/*.la; do \
		echo "Running $$test"; \
		./$(OUT_DIR)/mycompiler < $$test > $${test%.la}.c; \
	done
	@echo "All tests completed."

clean:
	rm -f mycompiler lex.yy.c myanalyzer.tab.* myanalyzer.output $(OUT_DIR)/*.c $(OUT_DIR)/*.h
	rm -rf $(OUT_DIR)/*.c $(OUT_DIR)/*.h
	rm -rf $(OUT_DIR)
	rm -rf $(OUT_DIR)/*.o
	rm -rf $(OUT_DIR)/*.dSYM
	rm -rf $(OUT_DIR)/*.exe
	rm -rf $(TEST_DIR)/*.c
