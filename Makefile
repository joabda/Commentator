########        Commentator Makefile      ########
#####                                        #####
#####      		Makefile written by 		 #####
#####				Joe Abdo	             #####
##################################################

EXEC = Commentator
CXXFLAGS = --std=c++17 -lstdc++fs -O0 -Wall 
DEBUG = no
CC= g++-8

.PHONY: all clean debug-memory debuging

all: $(EXEC)

$(EXEC): main.o Menu.o Header.o Parse.o ParseCpp.o ParseJava.o Directory.o LinuxNotification.o
	$(CC) -o $@ $^ $(CXXFLAGS)

main.o: main.cpp Menu.h Header.h Parse.h ParseCpp.h ParseJava.h Directory.h 
	$(CC) $(CXXFLAGS) -o $@ -c $< 

Menu.o: Menu.cpp Menu.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

Header.o: Header.cpp Header.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

Parse.o: Parse.cpp Parse.h Header.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

ParceCpp.o: ParceCpp.cpp ParceCpp.h Parce.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

ParceJava.o: ParceJava.cpp ParceJava.h Parce.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

Directory.o: Directory.cpp Directory.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

LinuxNotification.o: LinuxNotification.cpp LinuxNotification.h Directory.h
	$(CC) $(CXXFLAGS) -o $@ -c $<

# Instruction to clean file generated by compilation
# 	as well as text files used
clean:
	rm *.o && rm $(EXEC)

# # Instruction to clean the log file containing error message
# cleanLog:
# 	rm logFile.txt
	
# Instruction to check for memory leaks with valgrind
debug-memory: $(EXEC)
	valgrind --leak-check=full -v --show-leak-kinds=all\
	 --track-origins=yes ./$(EXEC)

# Instruction to compile and run at the same time
run: $(EXEC)
	./$(EXEC)
