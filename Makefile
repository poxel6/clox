WARNING_FLAGS=-Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wno-unused-const-variable -Wno-sign-conversion
FILE=./main.lox
FLAMEGRAPH=/home/conch/poxel6/third-party/FlameGraph

default:
	@clang -std=c23 -lc -Iinclude src/*.c -o ./target/main
	@./target/main $(FILE)

build:
	@clang -std=c23 -Iinclude src/*.c -o ./target/main

warn:
	@clang -std=c23 -Iinclude $(FLAGS) src/*.c -o ./target/main

debug:
	@clang -std=c23 -finstrument-functions -Iinclude -g src/*.c -o ./target/main
	@gf2 ./target/main $(FILE)

profile:
	@mkdir -p target/profiler
	@clang -std=c23 -O2 -g -Iinclude src/*.c -o ./target/main
	@perf record -F 99 -g -o target/profiler/perf.data -- ./target/main ./examples/performance.lox || true
	@perf script -i target/profiler/perf.data | $(FLAMEGRAPH)/stackcollapse-perf.pl | $(FLAMEGRAPH)/flamegraph.pl > target/profiler/flamegraph.svg
	@brave target/profiler/flamegraph.svg
