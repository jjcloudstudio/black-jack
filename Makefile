CXX=g++
CXXFLAGS= -std=c++11 -g -fprofile-arcs -ftest-coverage

LINKFLAGS=

SRC_DIR = src
SRCS = $(SRC_DIR)/*.cpp

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

MEMCHECK_RESULTS = ValgrindOut.xml

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

STATIC_RESULTS = CppCheckResults.xml

BROWSER = firefox

PROGRAM = blackjack
PROGRAM_TEST = testGame

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
		rm -rf *~ $(SRC)/*.o\
		*.gcov *.gcda *.gcno *.orig ???*/*.orig \
		*.bak ???*/*.bak $(PROGRAM) \
		???*/*~ ???*/???*/*~ $(COVERAGE_RESULTS) \
		$(PROGRAM_TEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR)  \
		$(DOXY_DIR)/html obj bin

$(PROGRAM): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) -I $(SRC_INCLUDE) $(SRCS) $(LINKFLAGS)

memory: $(PROGRAM)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM)

static: ${SRC_DIR}
	cppcheck --verbose --enable=all --xml ${SRC_DIR} ${INCLUDE} --suppress=missingInclude

style: ${SRC_INCLUDE} ${SRC_DIR}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${SRC_DIR}/*

docs: ${SRC_INCLUDE}
	doxygen docs/code/doxyfile
