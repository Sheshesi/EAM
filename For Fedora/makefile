.PHONY: clean game
SS = g++
SSFLAGS = -Wall -Werror -std=c++11
SR = src/
TRD = thirdparty/
BUL = build/
BIN = bin/
BUL_TEST = build/test/
all: $(BIN)prog

$(BIN)prog: $(BUL)main.o $(BUL)mySimpleComputer.o
	$(SS) -o $(BIN)game $(BUL)main.o $(BUL)mySimpleComputer.o $(BUL)myTerm.o

$(BUL)main.o: $(SR)main.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)main.cpp -o $(BUL)main.o

$(BUL)mySimpleComputer.o: $(SR)mySimpleComputer.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)mySimpleComputer.cpp -o $(BUL)mySimpleComputer.o

$(BUL)myTerm.o: $(SR)myTerm.hpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)myTerm.hpp -o $(BUL)myTerm.o

clean:
	rm -rf $(BUL)*.o
	rm -rf $(BIN)prog
run:
	$(BIN)prog