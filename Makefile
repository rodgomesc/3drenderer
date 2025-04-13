build:
	clang -Wall -std=c99 ./src/*.c -o renderer -lSDL3

run:
	./renderer
	
clean:
ifeq ($(OS),Windows_NT)
	del /Q /F renderer
else
	rm -f renderer
endif