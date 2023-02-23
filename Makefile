CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec.cpp llrec.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -o $@

stack: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) stack-test.cpp -o $@

heap: heap-test.cpp heap.h
	$(CXX) $(CXXFLAGS) heap-test.cpp -o $@

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 