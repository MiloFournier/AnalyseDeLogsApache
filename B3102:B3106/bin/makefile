OBJ = main.o Flux.o Stats.o

EXEC = analog

main: $(OBJ)
	g++ -o $(EXEC) $(OBJ)

main.o: main.cpp
	g++ -c main.cpp

Flux.o: Flux.cpp
	g++ -c Flux.cpp

Stats.o: Stats.cpp
	g++ -c Stats.cpp

clean: 
	rm $(EXEC) $(OBJ)
