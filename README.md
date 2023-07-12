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

## No build system

Without any build system help we are getting nasty `g++` invocation like this:

```
mkdir build
g++ -I include -o build/hello src/main.cpp src/mid/mid.cpp src/low/low.cpp
```

It works, but it is not nice and for more complicated project this would get much more ugly.