// #define DEBUG_EXPANSION_TREE

#include <queue>
#include "AdjacencyGraph.h"
#include "ExpansionTreeBuilder.h"

int main()
{
	ExpansionTreeBuilder<int> a(5);
	a.Build();
}
