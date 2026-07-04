WARNING_FLAGS=-Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wno-unused-const-variable -Wno-sign-conversion
default:
	@clang -Iinclude src/*.c -o ./target/main
	@./target/main

warn:
	@clang -Iinclude $(FLAGS) src/*.c -o ./target/main
	@./target/main
