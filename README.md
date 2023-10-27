# Chess CLI

This is a university final project of a C course.

The main goal is to create a chess CLI program written in C.

The specification is the following.
- The program must use Makefile or CMake to build the main program and execute tests.
- The program must contain a library that supports the main program.
- The library must:
  - Initialize the starting position and store it as an internal state.
  - Move: Modifies the internal state based on the move.
    - It isn't needed to check whether the move is regular or not.
    - Move must support capture, castle and promotion.
  - Moves must be reversible until the starting position is reached.
- The main program must implement a chess game with the help of the library.
  - When reading the input for moves it must print an error in case of 'irregular' moves and prompt the user for another move. Irregular moves are the following:
    - when white tries to move with a black figure or reverse.
    - when there is no figure.
  - It must be possible to:
    - resign the game,
    - offer a draw (that can be accepted or rejected).

General requirements:
- Libraries must be general libraries (standard header interface and C implementation) and also avoid the header file sphagetti/entaglement.
- If something is easier or more reasonable to implement with macro expression then it should be implemented with it.
- Extra informations in case of debug build.
- Unit (for the library) and integration tests (for the main program) that has particular targets.
- The program is also examined by dynamic tests. Example: it must not leak memory.
- Program should be safe against buffer overflow attacks.

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

There were integration tests but they were not as useful as intented to be
and they also were platform specific.
