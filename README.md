# Loremipsum 🔡

Loremipsum is an “interpreter” made on C that converts a string “Loremipsum” to an ASCII character.

Current version: **0.2.2-alpha**

> [!WARNING]
> Loremipsum is currently in ***ALPHA***, much of what is said here may not be implemented yet. ***Be careful!***

## Getting Started 🎯

### Dependencies / Requirements 🗃️

#### Dependencies

- [CLRSTR.h](https://github.com/hppsrc/libs/blob/main/C/CLRSTR.h) (Build 25011820)

#### Requirements

- `clang >19`
  - via MSYS2 for Windows. (using CLANG64)

- `mingw-w64-gcc`
  - for Windows Building on Linux.

### Build yourself 🛠️

- Using `make`:

        make build

> [!NOTE]
> The makefile doesn't allow you to create a Linux binary from Windows, only from Linux to Windows.

### Download ⬇️

Download last binaries for:

- [Windows x64](https://github.com/hppsrc/Loremipsum/releases/download/0.2.2-alpha/linter_Windows_x86_64.exe)
- [Linux x64](https://github.com/hppsrc/Loremipsum/releases/download/0.2.2-alpha/linter_Linux_x86_64.tar.gz)

### Installing ⚙️

*No installation required.*

### Using Loremipsum 💻

- You must pass as argument a file of the type `.loremipsum`:

        linter.exe file.loremipsum

- You can also use some flags:

        linter.exe --o file.loremipsum

> [!WARNING]
> No flags have been implemented yet

The file format is as follows:

```JS
LOREMIPSUM LOREMIPSUM loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum 
LOREMIPSUM LOREMIPSUM LOREMIPSUM loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum 
```

This code gives you as output `Hi`.

Uppercase `LOREMIPSUM` is 32.

Lowercase `loremipsum` is 1.

The file can have a maximum of 255 lines, any extra line will be ignored.

Each line is interpreted one by one and stored in the array, at the end of which the result or an error message is printed, also as to end with a space.

At each match, 1 or 32 is added to the position array based on the current line.

- [Reference](https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html).

## Help ❓

Run the next switch to get help.

        linter.exe --help

## License 🔑

This project is licensed under the GNU Lesser General Public License v3.0 (LGPLv3).

## TODO ✔️

- [x] Ensure compatibility with Windows and Linux.
- [x] Linux build.
- [ ] Proper code documentation.

## Known Errors 🐞

None found!

## Version History 🕒

- 0.2.0-alpha
  - Now you can modify the string that is taken as file format and reference for the detection process.
  - Implemented a function to process the text and one to check if the file is valid.
  - linter.exe can now interpret a .loremipsum file, but only when it is a single argument, commands will be implemented soon.
  - Added warning notice.
  - Added a (temporary) icon to the program.
  - Simple code formatting.

- 0.1.0-alpha
  - Initial Release.
  - Basic functions implementation.
