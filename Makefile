CXX=clang++

main: main.cpp transaction.cpp
	# ${CXX} -g -o main main.cpp transaction.cpp -lcrypto -D_GLIBCXX_USE_CXX11_ABI=0 -fno-limit-debug-info 
	g++ -g -Wall -std=c++11 -o main main.cpp transaction.cpp -lcrypto

clean:
	rm -rf *.o main
