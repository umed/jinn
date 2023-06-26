.PHONY: build
build:
	cmake --build build/ -- -j$(nproc)

.PHONY: configure
configure:
	cmake -S . -B build/

.PHONY: clean
clean:
	rm -rf build/
