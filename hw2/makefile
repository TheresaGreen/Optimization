
all: bin/.dirstamp bin/hw2
	./bin/hw2

bin/hw2: bin/llistint.o bin/removetest.o bin/.dirstamp
	g++ -g -Wall bin/llistint.o bin/removetest.o -o bin/hw2

bin/llistint.o: llistint.h llistint.cpp bin/.dirstamp
	g++ -g -Wall -c llistint.cpp -o bin/llistint.o

bin/removetest.o: llistint.h removetest.cpp bin/.dirstamp
	g++ -g -Wall -c removetest.cpp -o bin/removetest.o

bin/.dirstamp:
	mkdir -p bin
	touch bin/.dirstamp

.PHONY: clean
clean:
	rm -rf bin
