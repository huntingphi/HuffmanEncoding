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
4. Alternatively, the executable binary can be found in the bin folder and executed from the terminal using huffencode <input_file><output_file>, or bin/huffencode <input_file><output_file> from the root directory.
5. Run `make clean` to delete any artifacts created when compiling & running the compression program.

#### Running the Unit Tests

1. Navigate to the project root directory `Containers`.
2. Run `make tests` to build the executable, `test` in the `build/Tests` directory.
3. Run `make test-all` to run the `tests-node` and `tests-tree` executables.
4. Run `make clean` to delete any artifacts created when running the tests.

#### Additional notes

1. The parent node is initialised to a key value of char(-2) when no key value exists - this is to provide total control over the fields because if this value was not assigned then it would be up to the compiler to determine its value
2. The EOF character is represented by as char(-1). This value is included in the code table so that when reading in the bit stream, during extraction, the program will know to stop reading in when it reads in the EOF character
3. Compressed files will have a .hc extension
4. Compressed bit streams will have no extension
5. The <output_file>.hdr file makes use of JSON format to store the code table
6. "lorem.txt" is the file I use for testing
7. When converting to a bit stream, the "single int as header which lists the number of bits in the file" is stored as <file_name>.data
8. The last test case passes an encoded string to the compressToBits method, then reads the resulting file with unpackBits and tests it against the original encoded string
9. When the program is executed it will generate a file containing a string (.hc), a containing a bit stream, a file listing the number of bits in the bit stream (.data) and a JSON representaion of the code table (.hdr)
