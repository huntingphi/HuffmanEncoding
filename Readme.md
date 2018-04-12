# CSC3022H - Assignment 3 - Huffman Tree Encoding

Jethro Moller  
12 April 2018

----

# Instructions

#### Running the compression

1. Navigate to the project root directory `Containers`.
2. Run `make` to build the executable, `huffencode` in the `build` directory.
3. Run `make run ARGS="<input_file> <output_file>"` to run `huffencode` with the given input and output names.  
   NB: These files should be in the `assets` directory, and the resulting output will be in the `assets` directory.
4. Alternatively, the binary can be found in the bin folder and executed from the terminal using huffencode <input_file><output_file>, or bin/huffencode <input_file><output_file> from the root directory.
5. Run `make clean` to delete any artifacts created when compiling & running the compression program.

#### Running the Unit Tests

1. Navigate to the project root directory `Containers`.
2. Run `make tests` to build the executable, `test` in the `build/Tests` directory.
3. Run `make test-all` to run the `tests-node` and `tests-tree` executables.
4. Run `make clean` to delete any artifacts created when running the tests.

#### Additional notes

1. The parent node is initialised to a key value of char(-2) when no key value exists
2. The EOF character is represented by as char(-1). When reading in the bit stream the program will know to stop reading in when it reads in the character
3. Compressed files will have a .hc extension
4. Compressed bit streams will have a .hc.bit extension
5. The <output_file>.hdr file makes use of JSON format to store the code table
6. "lorem.txt" is the file I use for testing
