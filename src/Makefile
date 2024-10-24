CC = g++
FUNC_DIR = functions
SRC = $(wildcard $(FUNC_DIR)/*.cpp)
OBJ = $(SRC:.cpp=.o)
LIB = s21_matrix_oop.a
FLAGS = -Wall -Werror -Wextra -std=c++17
GTEST_DIR := $(shell brew --prefix googletest)
LDFLAGS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread
CHECK_FLAG = -lstdc++
LCOVFLAGS = --ignore-errors inconsistent --ignore-errors mismatch
OPEN= open

SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Linux)
    SYSTEM_FLAGS = -lcheck -lpthread -lrt -lsubunit -lm
else ifeq ($(SYSTEM), Darwin)
    SYSTEM_FLAGS = -lcheck
endif

# Файлы тестов
TEST_SRC = ./tests/tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_BIN = test

all: $(LIB)

$(LIB): $(OBJ)
	ar -rcs $(LIB) $(OBJ)
	ranlib $(LIB)

%.o: %.cpp
	$(CC) $(FLAGS) -I$(GTEST_DIR)/include -c $< -o $@

test: $(TEST_OBJ) $(LIB)
	$(CC) $(FLAGS) -o $(TEST_BIN) $(TEST_OBJ) $(LIB) $(LDFLAGS)
	./$(TEST_BIN)

./tests/%.o: ./tests/%.cpp
	$(CC) $(FLAGS) -I$(GTEST_DIR)/include -c $< -o $@

gcov_report: add_coverage_flag test
	./$(TEST_BIN)
	lcov -t "test" -o test.info -c -d ./  --no-external $(LCOVFLAGS)
	lcov --remove test.info '*/tests/*.cpp' -o test_filtered.info
	genhtml -o report test_filtered.info $(LCOVFLAGS)
	$(OPEN) report/index.html

add_coverage_flag:
	$(eval FLAGS += -fprofile-arcs -ftest-coverage)
	$(eval LDFLAGS += -fprofile-arcs -ftest-coverage)

style:
	cp ../materials/linters/.clang-format .
	clang-format -n *.h
	clang-format -n ./functions/*.cpp
	clang-format -n ./tests/*.cpp
	rm -rf .clang-format

push:
	git add .
	git commit -m "update code based on `date`"
	git push

clean:
	rm -rf $(LIB) $(TEST_BIN) $(OBJ) $(TEST_OBJ) *.gc* gcov_report coverage.info coverage_report/* tests/*.gcda tests/*.gcno functions/*.gcda functions/*.gcno test.info test_filtered.info report
	rm -rf report_html
	rm -rf coverage_report

valgrind: $(TEST_BIN)
	valgrind --tool=memcheck --leak-check=yes ./$(TEST_BIN)
