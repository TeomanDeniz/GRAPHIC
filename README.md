# GRAPHIC
A cross platform graphic library for C

## Installation to your project

Pull with:

```sh
git clone --recurse-submodules "git@github.com:TeomanDeniz/GRAPHIC.git"
```

Or if you're downloading manually, please also download the latest version of [LIBCMD](https://github.com/TeomanDeniz/LIBCMT) and put it inside `GRAPHIC` folder with `LIBCMD` name. (`./<THIS REPO>/GRAPHIC/LIBCMD`)

Make the static library by typing `make` on console. (Both in Windows CMD and Unix Shell)

Then just include the GRAPHIC.h to use this library:

```c
#include "GRAPHIC/GRAPHIC.h"
```

And compile your project with static library that created.

```sh
gcc my_project.c ./GRAPHIC/graphic.a
```

And that's all.
