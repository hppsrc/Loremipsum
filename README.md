# Loremipsum 🔡

Loremipsum is an “interpreter” made on C that converts a string “Loremipsum” to an ASCII character.

Current version: **0.1.0-alpha**

> [!WARNING]
> Loremipsum is currently in ***ALPHA***, much of what is said here may not be implemented yet. ***Be careful!***

> [!NOTE]
> The project aims at a code compatible with Windows and Linux (preferably Arch, so far not tested).
>
> But because of the way C is, it will most likely work.

## Getting Started 🎯

### Dependencies 🗃️

- [CLRSTR.h](https://github.com/hppsrc/libs/blob/main/C/CLRSTR.h) (Build 25011213)

### Build yourself 🛠️

#### Windows

Using clang 19.1.4 (via MSYS2)

- On your console use:

        clang .\src\main.c

### Download ⬇️

Download last binaries here.

<!-- - Last version for
  - Windows: ***0.1.0-alpha*** -->

### Installing ⚙️

*No installation required.*

### Using Loremipsum 💻

> [!WARNING]
> Currently the code doesn't execute any action.

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

## Known Errors 🐞

None found!

## Version History 🕒

- 0.1.0-alpha
  - Initial Release.
  - Basic functions implementation.