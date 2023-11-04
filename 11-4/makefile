.PHONY:all
all:mytest mykill

mykill:mykill.cc
	g++ -o $@ $^ -std=c++11
mytest:mytest.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f mytest mykill