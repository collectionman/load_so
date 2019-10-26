build:
	-@ rm -r ./bin/ 
	-@ mkdir bin
	-@ g++ -shared -Wall -fPIC ./src/hello.cpp -o ./bin/hello.so
	-@ g++ -shared -Wall -fPIC ./src/goodbye.cpp -o ./bin/goodbye.so
	-@ g++ -Wall -std=c++11 ./src/main.cpp -ldl -o ./bin/main.bin

run:
	-@./bin/main.bin