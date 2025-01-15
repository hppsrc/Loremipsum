# Loremipsum 🔡

Loremipsum is an “interpreter” made on C that converts a string “Loremipsum” to an ASCII character.

Current version: **0.2.0-alpha**

> [!WARNING]
> Loremipsum is currently in ***ALPHA***, much of what is said here may not be implemented yet. ***Be careful!***

> [!NOTE]
> The project aims at a code compatible with Windows and Linux (preferably Arch, so far not tested).
>
> But because of the way C is, it will most likely work.

## Getting Started 🎯

### Dependencies 🗃️

- [CLRSTR.h](https://github.com/hppsrc/libs/blob/main/C/CLRSTR.h) (Build 25011316)

### Build yourself 🛠️

#### Windows

Using clang 19.1.4 (via MSYS2)

- Compile resources:

        windres .\src\res\res.rc -O coff -o app.res

- Compile source code:

        clang .\src\main.c app.res

### Download ⬇️

Download last binaries for:

- [Windows (x64)](https://github.com/hppsrc/Loremipsum/releases/download/0.2.0-alpha/linter_x86_64.exe).

### Installing ⚙️

*No installation required.*

### Using Loremipsum 💻

- You must pass as argument a file of the type `.loremipsum`.

        lintr.exe file.loremipsum

The file format is as follows:

```JS

LOREMIPSUM LOREMIPSUM loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum 
LOREMIPSUM LOREMIPSUM LOREMIPSUM loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum loremipsum 

```

This code gives you as output `Hi`.

Uppercase `LOREMIPSUM` is 32.

lowercase `loremipsum` is 1.

The file can have a maximum of 255 lines, any extra line will be ignored.

Each line is interpreted one by one and stored in the array, at the end of which the result or an error message is printed.

At each match, 1 or 32 is added to the position array based on the current line.

- [Reference](https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)

## Help ❓

Run the next switch to get help.

        lintr.exe --help

## License 🔑

This project is licensed under the GNU Lesser General Public License v3.0 (LGPLv3).

## TODO ✔️

- [ ] Ensure compatibility with Windows and Linux.
- [ ] Arch Linux build.
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