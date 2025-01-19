VERSION = 0.2.2-alpha
BUILD := 250118211

CC = clang
CFLAGS = -std=c23 -Wall -Wextra -pedantic -march=native -fsanitize=address

ifeq ($(shell uname -s), Linux)
    EXT = .out
	OS = Linux
else
    EXT = .exe
	OS = Windows
endif

ARCH := $(shell uname -m)

build: ./src/main.c
	@echo "Building linter for $(OS) $(ARCH)..."
	@$(CC) ./src/main.c -o linter_$(OS)_$(ARCH)$(EXT)
	@echo "Done!"

test: ./src/main.c
	@echo "Building test linter for $(OS) $(ARCH)..."
	@$(CC) ./src/main.c $(CFLAGS) -o linter_$(VERSION)_$(BUILD)_$(ARCH)$(EXT)
	@echo "Done!"

all: ./src/main.c
ifeq ($(shell uname -s), Linux)
	@echo "Building Linter for Linux x86_64..."
	@$(CC) ./src/main.c -o linter_Linux_x86_64.out
	@echo "Creating tar.gz..."
	@tar -czvf linter_Linux_x86_64.tar.gz linter_Linux_x86_64.out
	@echo "Building Linter for Windows x86_64..."
	@x86_64-w64-mingw32-gcc ./src/main.c -o linter_Windows_x86_64.exe
else
	@echo "Command available only in Linux, for now."
endif

clean:
	@rm -f linter_$(OS)_$(ARCH)$(EXT) linter_$(VERSION)_$(BUILD)_$(ARCH)$(EXT) linter_Linux_x86_64.out linter_Windows_x86_64.exe linter_Linux_x86_64.tar.gz
	@echo "Done!"
