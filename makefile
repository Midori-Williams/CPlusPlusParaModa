all:
	g++ -std=c++11 ThreeNodes.cpp QueryGraph.cpp ExpansionTreeNode.cpp Mapping.cpp FourNodes.cpp FiveNodes.cpp Utils.cpp Program.cpp MODATest.cpp ModaAlgorithms.cpp
runTestExpansion:
	g++ -std=c++11 ExpansionTreeBuilderTest.cpp ThreeNodes.cpp FourNodes.cpp FiveNodes.cpp QueryGraph.cpp ExpansionTreeNode.cpp Mapping.cpp
	./a.out
