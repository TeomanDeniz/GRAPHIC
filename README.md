# LibCGFX (C Graphics Library)
A cross-platform graphics library written in C and designed for use in C projects.

## Installation to your project

Pull with:

```sh
git clone --recurse-submodules "git@github.com:TeomanDeniz/LIBCGFX.git"
```

Or if you're downloading manually, please also download the latest version of [LIBCMT](https://github.com/TeomanDeniz/LIBCMT) and put it inside your project folder with `LIBCMT` name. (`./<THIS REPO>/LIBCMT`)

### Compiling in Windows Systems

First, please install a C Compiler. For example: [GNU_GCC](https://sourceforge.net/projects/gcc-win64/files/14.2.0/gcc-14.2.0-no-debug.7z/download)

Then extract the zip file inside the folder like in `C\MinGW\`.

Then set your path into that compiler's bin folder:

```bat
SETX PATH "%PATH%;C\MinGW\bin"
```

Once you done that, you now have a C Compiler. Now compile your graphic engine with `make`.

This is going to create a `LIBCGFX.a` static library.

Then compile your project using this file. And don't forget to include the `.h` file in your code:

```c
#include "./LIBCGFX.h"
```

```sh
gcc my_project.c ./LIBCGFX.a
```

### Compiling in Unix Systems

First, please install a C Compiler:

- **Ubuntu, Debian**: `sudo apt install build-essential`

- **Arch Linux**: `sudo pacman -S base-devel`

- **Fedora**: `sudo dnf groupinstall "Development Tools"`

- **openSUSE**: `sudo zypper install -t pattern devel_basis`

For `-lX11`:

- **Ubuntu, Debian**: `sudo apt install libx11-dev`

- **Arch Linux**: `sudo pacman -S libx11`

- **Fedora**: `sudo dnf install libX11-devel`

- **openSUSE**: `sudo zypper install libX11-devel`

For `-lasound`:

- **Ubuntu, Debian**: `sudo apt install libasound2-dev`

- **Arch Linux**: `sudo pacman -S alsa-lib`

- **Fedora**: `sudo dnf install alsa-lib-devel`

- **openSUSE**: `sudo zypper install alsa-devel`

Once you have necessary libraries for your C Compiler, compile it with `make`.

This is going to create a `LIBCGFX.a` static library.

Then compile your project using this file and `.h` file:

```c
#include "./LIBCGFX.h"
```

```sh
gcc my_project.c ./LIBCGFX.a
```
