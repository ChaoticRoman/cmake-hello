.PHONY: build run clean

build:
	cmake -S . -B build -G Ninja
	cmake --build build

run: build
	./build/hello

clean:
	rm -rf build
