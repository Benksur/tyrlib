BUILD_DIR := build
CMAKE := cmake

.PHONY: all configure build test test-file clean sanitize

all: build

configure:
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

build: configure
	$(CMAKE) --build $(BUILD_DIR)

test: build
	ctest --test-dir $(BUILD_DIR) --output-on-failure 

test-file: build
	ctest --test-dir $(BUILD_DIR) -R '$(TEST)' --output-on-failure 

sanitize:
	$(CMAKE) -S . -B build-sanitize \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DTYRLIB_SANITIZERS=ON
	$(CMAKE) --build build-sanitize
	ctest --test-dir build-sanitize --output-on-failure

clean:
	$(CMAKE) -E rm -rf $(BUILD_DIR) build-sanitize
