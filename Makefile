CXX=g++
CXXFLAGS= -std=c++11 -g -fprofile-arcs -ftest-coverage

LINKFLAGS= -lgtest

SRC_DIR = src
SRCS = $(SRC_DIR)/*.cpp
GAME_MAIN = $(SRC_DIR)/game/main.cpp

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

TEST_DIR = test
TEST_SRCS = $(TEST_DIR)/*.cpp

MEMCHECK_RESULTS = ValgrindOut.xml

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

STATIC_RESULTS = CppCheckResults.xml

PROGRAM = cardGame
PROGRAM_TEST = testGame
GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage

DOXY_DIR = docs/code

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o	$(PROGRAM) $(COVERAGE_DIR) $(COVERAGE_RESULTS) *.gcda *.gcno $(PROGRAM_TEST) $(DOXY_DIR)/src/html

$(PROGRAM): $(SRCS) $(GAME_MAIN)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRCS) $(GAME_MAIN) $(LINKFLAGS)

$(PROGRAM_TEST): $(SRCS) $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) -I $(SRC_INCLUDE) $(SRCS) $(TEST_SRCS) $(LINKFLAGS)

.PHONY: coverage
coverage: $(PROGRAM_TEST)
	$(PROGRAM_TEST)
	# Determine code coverage
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS) --rc lcov_branch_coverage=1
	# Only show code coverage for the source code files (not library files)
	$(LCOV) --extract $(COVERAGE_RESULTS) */$(PROJECT_DIR)/$(SRC_DIR)/* -o $(COVERAGE_RESULTS)
	#Generate the HTML reports
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	#Remove all of the generated files from gcov
	rm -f *.gcda *.gcno

.PHONY: memcheck-game
memcheck-game: $(PROGRAM)
	valgrind --tool=memcheck --leak-check=full --error-exitcode=1 $(PROGRAM)

.PHONY: memcheck-test
memcheck-test: $(PROGRAM_TEST)
	valgrind --tool=memcheck --leak-check=full --error-exitcode=1 $(PROGRAM_TEST)

.PHONY: static
static: ${SRC_DIR} $(TEST_DIR)
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${TEST_DIR} ${SRC_INCLUDE} --suppress=missingInclude --error-exitcode=1

.PHONY: style
style: ${SRC_DIR} ${GTEST_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
	${STYLE_CHECK} ${SRC_DIR}/* ${TEST_DIR}/* ${SRC_INCLUDE}/* ${GAME_MAIN}

.PHONY: docs
docs: ${SRC_INCLUDE}
	doxygen $(DOXY_DIR)/doxyfile
