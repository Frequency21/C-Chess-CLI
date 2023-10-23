# Chess CLI

## Compiling and running

```sh
cmake -H. -Bbuild
```

Build the main program

```sh
cmake --build build -t main
```

Run the compiled program, have fun!

```sh
./build/src/main
```

## Running tests

For tests to work you have to set build type to `Debug`.

```sh
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
```

### Unit tests

```sh
cmake --build build -t unit-tests
```

Execute unit tests with ctest.

```sh
ctest --test-dir build -V
```

### Integration tests

There were integration tests but they were not as useful as should be
and they also were platform specific.
