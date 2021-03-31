CXX=clang++

main: main.cpp transaction.cpp
	${CXX} -g -o main main.cpp transaction.cpp

clean:
	rm -rf *.o main
