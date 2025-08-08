main: src/main.c
	gcc -std=c23 -Wall -Wextra -Werror -pedantic -fexec-charset=UTF-8 "./src/*.c" -o "./build/synk.exe"

run: ./build/synk.exe
	make main
	./build/synk.exe

debug: src/main.c
	gcc -std=c23 -Wall -Wextra -Werror -pedantic -fexec-charset=UTF-8 -g "./src/*.c" -o "./build/synk.exe"

clean:
	rm -f "..\build\synk.exe"
