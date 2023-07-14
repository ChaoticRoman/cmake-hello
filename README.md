# CMake Hello

Testing how to set up cmake for project with following structure:

```
.
├── include
│   ├── low
│   │   └── low.h
│   └── mid
│       └── mid.h
└── src
    ├── low
    │   └── low.cpp
    ├── main.cpp
    └── mid
        └── mid.cpp
```

and following dependencies (`A -> B` means `A` depends on `B`):

```
main -> mid -> low
```

Check commits one-by-one as they:

1. start with not using CMake at all and building the thing using plain g++,
1. use the simplest CMake 
1. Hide the growing complexity to Makefile
1. Adds configure, build and test to GitHub pipeline.

### TODO

1. Use hierarchical CMake files
2. Testing
3. Linting
4. Use external dependencies
5. Use CPM

## No build system

Without any build system help we are getting nasty `g++` invocation like this:

```
mkdir build
g++ -I include -o build/hello src/main.cpp src/mid/mid.cpp src/low/low.cpp
```

You can run your program using

```
./build/hello
```

It works, but it is not nice and for more complicated project this would get much more ugly.

## Using CMake

All configuration is set in the [`CMakeLists.txt`](/CMakeLists.txt) file.

Configure is required when modifying configuration, adding, renaming or moving files,
or when inter-files dependencies are changed and for the first run of coure.
It is done for `make` build system by

```
cmake -S . -B build/
```

or e.g. to use `ninja`

```
cmake -S . -B build/ -G Ninja
```

The build itself then goes with:

```
cmake --build build/
```

You can run your program using

```
./build/hello
```

## Hiding the complexity

It started to get bit ugly in previous section so we added helper Makefile
to run previous commands. Now you can just use `make run` 

## Debugging cmake projects with VS code

[This guide][vscode] describes how to get debugger working. It is surprisingly neat, only
thing to be aware of is that it does not binds to built-in Debug/Run (F5/Ctrl+F5)
functionality but uses bottom bar buttons.

[vscode]: https://www.pragmaticlinux.com/2021/07/import-a-cmake-project-into-visual-studio-code/

## References

* https://blog.feabhas.com/2021/06/why-we-need-build-systems/
* https://blog.feabhas.com/2021/07/cmake-part-1-the-dark-arts/
