CC = g++ -std=c++11

all:a.out

a.out: main.o FileSender.o Client.o FileReciver.o Server.o Exceptions.o
	$(CC) main.o FileSender.o Client.o FileReciver.o Server.o Exceptions.o -o a.out

main.o: main.cpp FileSender.hpp FileReciver.hpp Server.hpp Client.hpp
	$(CC) -c main.cpp

FileSender.o: FileSender.cpp FileSender.hpp Exceptions.hpp
	$(CC) -c FileSender.cpp

Client.o: Client.cpp Client.hpp FileSender.hpp
	$(CC) -c Client.cpp

FileReciver.o: FileReciver.cpp FileReciver.hpp Exceptions.hpp
	$(CC) -c FileReciver.cpp

Server.o: Server.cpp Server.hpp FileReciver.hpp
	$(CC) -c Server.cpp

Exceptions.o: Exceptions.cpp Exceptions.hpp
	$(CC) -c Exceptions.cpp

.PHONY: clean
clean:
	rm *.o
	rm a.out