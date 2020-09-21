mydictionary: main.cpp normalbinary.o starbinary.o quesbinary.o
	g++ -o $@ main.cpp normalbinary.o starbinary.o quesbinary.o
normalbinary.o: header.h normalbinary.cpp
	g++ -c normalbinary.cpp -o $@
starbinary.o: header.h starbinary.cpp
	g++ -c starbinary.cpp -o $@
quesbinary.o: header.h quesbinary.cpp
	g++ -c quesbinary.cpp -o $@

clean:
	rm mydictionary
	rm *.o
