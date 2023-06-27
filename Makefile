.PHONY: build
build:
	cmake --build build/ -- -j 4

.PHONY: configure
configure:
	cmake -S . -B build/

.PHONY: clean
clean:
	rm -rf build/
