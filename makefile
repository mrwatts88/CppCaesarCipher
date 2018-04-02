
caesar.out : main.o
	g++ -o caesar.out main.o

main.o : main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o
	touch *
