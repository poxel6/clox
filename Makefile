WARNING_FLAGS=-Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wno-unused-const-variable -Wno-sign-conversion
default: build
	@clang -std=c23 -Iinclude src/*.c -o ./target/main
	@./target/main ./main.lox

build:
	@clang -std=c23 -Iinclude src/*.c -o ./target/main

warn:
	@clang -std=c23 -Iinclude $(FLAGS) src/*.c -o ./target/main
	@./target/main

debug:
	@clang -std=c99 -Iinclude -g src/*.c -o ./target/main
	gf2 ./target/main

