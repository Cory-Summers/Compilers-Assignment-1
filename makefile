OBJS	  = driver-class.o encode-string.o main.o print-values.o lex.yy.o token_parser.tab.o
SOURCE	= driver-class.cpp encode-string.cpp main.cpp print-values.cpp lex.yy.cc token_parser.tab.cc
HEADER	= token_parser.tab.hh driver-class.hpp encode-string.hpp parser.hpp print-values.hpp scanner-token.hpp token-scanner-class.hpp location.hh stack.hh position.hh context-class.hpp
BISONFILES = location.hh position.hh lex.yy.cc stack.hh token_parser.tab.hh token_parser.tab.cc
OUT	    = c-
CC	    = g++
FLAGS	  = -g -c -Wall
LFLAGS	= 

all: bison lexer $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
bison: token_parser.y
	bison token_parser.y -d -L c++ -t
lexer: scanner.flex
	flex $<
driver-class.o: driver-class.cpp
	$(CC) $(FLAGS) driver-class.cpp -std=c++14

encode-string.o: encode-string.cpp
	$(CC) $(FLAGS) encode-string.cpp -std=c++14

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14

print-values.o: print-values.cpp
	$(CC) $(FLAGS) print-values.cpp -std=c++14

lex.yy.o: lex.yy.cc
	$(CC) $(FLAGS) lex.yy.cc -std=c++14

token_parser.tab.o: token_parser.tab.cc
	$(CC) $(FLAGS) token_parser.tab.cc -std=c++14


clean:
	rm -f $(OBJS) $(BISONFILES) $(OUT)