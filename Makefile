# Define a specific installation path
TO ?= "..."

.PHONY: all clean install

install:
	@echo "\033[1;92mBuilding and installing nguyenpanda to path\033[1;94m $(TO)\033[0m"
	@if [ "$(TO)" = "..." ]; then \
		echo "\033[1;91mError: TO=\"${TO}\" is not set. Please provide a valid installation path by providing TO='your/prefix/path'\033[0m"; \
		exit 1; \
	fi
	mkdir -p build
	cd build && cmake -DCMAKE_INSTALL_PREFIX=$(TO) ..
	cd build && make install

clean:
	@echo "Cleaning up..."
	rm -rf build
