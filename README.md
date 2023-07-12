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

### TODO

1. Use hierarchical CMake files
1. Use external dependencies
1. Use CPM

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
or when inter-files dependencies are changed and for the first run of coure. It is done by

```
cmake -S . -B build/
```

The build itself then goes with:

```

```

You can run your program using

```
./build/hello
```

## References

* https://blog.feabhas.com/2021/06/why-we-need-build-systems/
* https://blog.feabhas.com/2021/07/cmake-part-1-the-dark-arts/
