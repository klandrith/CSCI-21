output: rock_paper_scissors.o

rock_paper_scissors.o: rock_paper_scissors.cpp
	g++ -std=c++11 -Wno-psabi -o "rock_paper_scissors" "rock_paper_scissors.cpp"

target: dependencies
	action

clean:
	rm *.o output
