src := $(wildcard source/*.cpp)
main: $(src) main.cpp
	g++ main.cpp $(src) -o main
run:main
	./main
clean:
	rm main
