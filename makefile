VERSION = 0.2.2-alpha
BUILD = 250118211

CC = clang
CFLAGS = -std=c23 -Wall -Wextra -pedantic -march=native -fsanitize=address

ifeq ($(shell uname -s), Linux)
	OS = Linux
    EXT = .out
	RES = 
else
	OS = Windows
    EXT = .exe
	RES = app.res
endif

ARCH := $(shell uname -m)

build: ./src/main.c
ifeq ($(OS), Windows)
	@echo "Compiling Resources..."
	@windres .\res\res.rc -O coff -o app.res
endif
	@echo "Building linter for $(OS) $(ARCH)..."
	@$(CC) ./src/main.c $(RES) -o linter_$(OS)_$(ARCH)$(EXT)
	@echo "Done!"

test: ./src/main.c
	@echo "Building linter for $(OS) $(ARCH) [TEST]..."
	@$(CC) ./src/main.c $(CFLAGS) -o linter_$(VERSION)_$(BUILD)_$(ARCH)$(EXT)
	@echo "Done!"

all: ./src/main.c

ifeq ($(OS), Windows)

	@echo "Linux Building Disabled!"
	@echo "Compiling Resources..."
	@windres ./res/res.rc -O coff -o app.res
	@echo "Building Linter for Windows x86_64..."
	@$(CC) ./src/main.c app.res -o linter_Windows_x86_64.exe

else

	@echo "Building Linter for Linux x86_64..."
	@$(CC) ./src/main.c -o linter_Linux_x86_64.out
	@echo "Creating tar.gz..."
	@tar -czvf linter_Linux_x86_64.tar.gz linter_Linux_x86_64.out

	@echo "Building Linter for Windows x86_64..."
	@echo "Resources Compiling Disabled!"
	@x86_64-w64-mingw32-gcc ./src/main.c -o linter_Windows_x86_64.exe

endif

	@echo "Done!"


clean:
	@rm -f *.exe *.out *.tar.gz *.res
	@echo "Done!"
