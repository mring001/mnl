CXX = g++
INC = ../include
DEPS = ../obj

rational_test: rational_test.cc $(DEPS)/rational.o
	$(CXX) -I$(INC) -o $@ $^

matrix_test: matrix_test.cc
	$(CXX) -I$(INC) -o $@ $^
