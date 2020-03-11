CXXFLAGS = -g -Wall -Wextra -pthread -std=c++11
#-Werror

CPPFLAGS += -isystem $(GTEST_DIR)/include


GTEST_DIR= include/googletest
GTEST_LIB_DIR = $(GTEST_DIR)/make
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_LIBS = libgtest.a libgtest_main.a
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

USER_DIR = .
TESTS = unittest
EXEC = $(lastword $(notdir $(CURDIR)))

DIRS = image input iris utils fonction_activation tanh perceptron nn1 apprentissage sigmoide

all :
	$(MAKE) test
	./unittest
	$(MAKE) main
	$(MAKE) clean

clean :
	rm -rf $(GTEST_LIBS) $(TESTS) *.o unittest.dSYM $(EXEC)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I $(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

libgtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

libgtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

unittest.o : $(USER_DIR)/tests/unittest.cc	$(USER_DIR)/src/*/*.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/tests/unittest.cc

unittest : unittest.o objs $(USER_DIR)/src/*/*.hpp $(GTEST_LIBS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L $(GTEST_LIB_DIR) -lpthread ${GTEST_DIR}/src/gtest_main.cc $< $(DIRS:=.o) $(GTEST_LIBS) -o $@

main.o : $(USER_DIR)/src/main.cc  $(USER_DIR)/src/*/*.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

objs:
	for dir in $(DIRS); do \
		$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/src/$$dir/$$dir.cc ; \
	done

main : main.o objs
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $(DIRS:=.o) $< -o $(EXEC)

test : $(GTEST_LIBS) $(TESTS)


# FOLD = $(notdir $(CURDIR))
# SRC =  src/iris.cc src/input.cc
# HDR = src/iris.h src/input.h
# OBJ = $(SRC:.cc=.o)

# TST = tests/*.cc #tests/*.h

# EXEC = $(FOLD)


# all : $(OBJ)
# 	$(CXX) $(CXXFLAGS) $^ -o $(EXEC)

# clean :
# 	$(RM) $(EXEC) $(OBJ) $(TST:.cc=.o) gtest-all.o libgtest.a tests/test

# check : all
# 	./tests/test

# main.o : $(SRC) $(HDR)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)

# libgtest.a :
# 	$(CXX) $(CXXFLAGS) -isystem ${GTEST_DIR}/include -I ${GTEST_DIR} \
#     -pthread -c ${GTEST_DIR}/src/gtest-all.cc
# 	ar -rv libgtest.a gtest-all.o

# main_test.o : $(TST) $(HDR)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRC)

# test : libgtest.a libgtest_main.a main.o main_test.o
# 	$(CXX) $(CXXFLAGS) -isystem ${GTEST_DIR}/include -pthread $(TST) \
# 	${GTEST_DIR}/src/gtest_main.cc libgtest.a -o tests/test
# 	./tests/test
# 	make clean


# sample1.o : $(SRC) $(HDR) $(GTEST_HEADERS)
# 	$(CXX) $(CXXFLAGS) -isystem ${GTEST_DIR}/include -c $(SRC)

# sample1_unittest.o : $(TST) \
#                      $(HDR) $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -isystem ${GTEST_DIR}/include -c $(TST)

# sample1_unittest : libgtest.a sample1.o sample1_unittest.o 
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L$(GTEST_LIB_DIR) -lgtest_main -lpthread $^ -o $@