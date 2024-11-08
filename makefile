CXX = g++
TARGET = mytests
SOURCES = BSTNode.cpp BST.cpp RBTreeNode.cpp RBTree.cpp mytests.cpp
all: $(TARGET)
$(TARGET):
	$(CXX) -o $(TARGET) $(SOURCES)
test: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)
