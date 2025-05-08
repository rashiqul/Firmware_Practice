# =========================================
# Makefile for C++ Modular Project with GoogleTest + Coverage
# Author: Rashiqul
# =========================================

# -----------------------------------------
# Setup and configure the build directory
# -----------------------------------------
configure:
	@echo "[Config] Cleaning and setting up build directory..."
	rm -rf build
	mkdir build
	cd build && cmake ..
	@echo "[Config] ✅ Done. Run 'make build' or 'make run'"

# -----------------------------------------
# Compile the full project
# -----------------------------------------
build: configure
	cd build && cmake --build .

# -----------------------------------------
# Clean build files and coverage artifacts
# -----------------------------------------
clean:
	rm -rf build
	find . -name "*.gcda" -o -name "*.gcno" -o -name "*.gcov" -delete

# -----------------------------------------
# Run the main executable (if present)
# -----------------------------------------
run: build
	./build/main/Executable

# -----------------------------------------
# Run unit tests using GoogleTest (direct binary execution)
# -----------------------------------------
run-tests: build
	@echo "[Test] Running unit tests via GoogleTest..."
	./build/test/TestExecutable
	@echo "[Test] ✅ Tests finished. Review the output above."

# -----------------------------------------
# Generate coverage reports using gcovr
# Adjusted to use project root (..) to match real source paths
# -----------------------------------------
coverage:
	@echo "[Coverage] Running unit tests..."
	./build/test/TestExecutable

	@echo "[Coverage] Generating reports in build/coverage/..."
	cd build && mkdir -p coverage

	cd build && gcovr -r .. \
		--html --html-details -o coverage/index.html \
		--exclude '../test' \
		--exclude '.*googletest.*'

	cd build && gcovr -r .. \
		--xml -o coverage/coverage.xml \
		--exclude '../test' \
		--exclude '.*googletest.*'

	cd build && gcovr -r .. \
		--txt -o coverage/summary.txt \
		--exclude '../test' \
		--exclude '.*googletest.*'

	@echo "[Coverage] ✅ Done! Open build/coverage/index.html to view results."
