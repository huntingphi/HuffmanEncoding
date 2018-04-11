CXX = g++ # This is the main compiler
CXXFLAGS = -std=c++11 -Wall
VPATH = test src include bin build


build:

test-tree: 000-CatchMain.o Utils.o HuffmanNode.o HuffmanTree.o tests-huffmantree.o
	$(CXX) $(CXXFLAGS) -I ./include -o bin/test-tree build/000-CatchMain.o build/Utils.o build/HuffmanNode.o build/HuffmanTree.o build/tests-huffmantree.o && ./bin/test-tree --success


test-node: 000-CatchMain.o HuffmanNode.o tests-huffmannode.o
	$(CXX) $(CXXFLAGS) -I ./include -o bin/test-node build/000-CatchMain.o build/HuffmanNode.o build/tests-huffmannode.o && ./bin/test-node --success

tests-huffmannode.o: tests-huffmannode.cpp
	$(CXX) $(CXXFLAGS) -c test/tests-huffmannode.cpp -o build/tests-huffmannode.o

HuffmanNode.o: HuffmanNode.cpp
	$(CXX) $(CXXFLAGS) -c src/HuffmanNode.cpp -o build/HuffmanNode.o

tests-huffmantree.o: tests-huffmantree.cpp
	$(CXX) $(CXXFLAGS) -c test/tests-huffmantree.cpp -o build/tests-huffmantree.o


HuffmanTree.o: Utils.o HuffmanNode.o HuffmanTree.cpp
	$(CXX) $(CXXFLAGS) -c src/HuffmanTree.cpp -o build/HuffmanTree.o

Utils.o: Utils.cpp
	$(CXX) $(CXXFLAGS) -c src/Utils.cpp -o build/Utils.o

000-CatchMain.o: 000-CatchMain.cpp
	$(CXX) $(CXXFLAGS) -I ./include -c test/000-CatchMain.cpp -o build/000-CatchMain.o


clean:
	echo "Cleaning..."
	find . -type f \( -name "*.o" ! -name "000-CatchMain.o" -or -name "test" \) -delete
	# find . -type f \( -name "*.gch" -or -name "tests-utils" -or -name "runner" \) -delete
	find . -type f -name "*.gch"
