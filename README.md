# CPP_Concurrency_In_Action

Practice on book [C++ Concurrency in Action](https://www.manning.com/books/c-plus-plus-concurrency-in-action), code is
not the same as it was in the book, I modified the example source code to my own understanding.

## Usage

```shell
cd build
cmake ..
make
```

## Dependency

I'm using ubuntu16.04 and GCC 5.4, if you are using other platforms
you may want to modify the CMake file about

```shell
target_link_libraries (Listing2.2 pthread)
```

and any other code using pthread libarary.