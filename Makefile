src := $(wildcard source/*.cpp)
headers := $(wildcard include/*.h)
main: $(src) $(headers) main.cpp
	g++ main.cpp $(src) -o main
run:main
	./main
clean:
	rm main
