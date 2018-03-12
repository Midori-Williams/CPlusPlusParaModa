#include <iostream>
#include <queue>
#include "AdjacencyGraph.h"
#include "QueryGraph.h"
#include "ExpansionTreeNode.h"
#include "AdjacencyGraph.h"
#include "ThreeNodes.h"
#include "FourNodes.h"
#include "FiveNodes.h"

using namespace std;

template<class TVertex>
ExpansionTreeBuilder<TVertex>::ExpansionTreeBuilder()
{

}

template<class TVertex>
ExpansionTreeBuilder<TVertex>::ExpansionTreeBuilder(int numberOfNodes)
{
	_numberOfNodes = numberOfNodes;
	NumberOfQueryGraphs = 1;
	//ExpansionTree = AdjacencyGraph<ExpansionTreeNode*>;

	// ExpansionTree.EdgeAdded += e => e.Target.ParentNode = e.Source;
}

template<class TVertex>
vector<ExpansionTreeNode*> ExpansionTreeBuilder<TVertex>::sortWithBFS(AdjacencyGraph<ExpansionTreeNode*> tree, ExpansionTreeNode* root)
{
	map<string, bool> visitedNodes;
	vector<ExpansionTreeNode*> retVal;
    cout << "root address: " << root << " root name:" << root->NodeName << endl;
	queue<ExpansionTreeNode*> q;
	q.push(root);
	visitedNodes[root->NodeName] = true;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
    cout << q.size() << endl;
	while(q.size() > 0)
	{
		ExpansionTreeNode* current = q.front();
		q.pop();

		vector<Edge<ExpansionTreeNode*> > edges;
		tree.TryGetOutEdges(current, edges);

		// current.marked = true;

		for(auto & edge : edges)
		{
			// cout << edge.Target.ToString() << endl;
            if(visitedNodes[edge.Target->NodeName] != true)
			{
				q.push(edge.Target);
				// edge.Target.marked = true;
                visitedNodes[edge.Target->NodeName] = true;
				retVal.push_back(edge.Target);
			}
		}
	}



	return retVal;
}

template<class TVertex>
void ExpansionTreeBuilder<TVertex>::Build()
{
	ExpansionTreeNode* rootNode;
	switch (_numberOfNodes)
	{
		case 3:
			rootNode = ThreeNodes::BuildThreeNodesTree(ExpansionTree);
			NumberOfQueryGraphs = 2;
			break;
		case 4:
			rootNode = FourNodes::BuildFourNodesTree(ExpansionTree);
			NumberOfQueryGraphs = 6;
			break;
		case 5:
			rootNode = FiveNodes::BuildFiveNodesTree(ExpansionTree);
            //cout << ExpansionTree.getEdgeCount() << endl;
			NumberOfQueryGraphs = 21;
			break;
		default:
			cerr << "Subgraph sizes below 3 and above 5 are not supported, unless you supply a query graph." << endl;
	}
    
	vector<ExpansionTreeNode*> VerticesSortedVect = sortWithBFS(ExpansionTree, rootNode);
	for(auto & i : VerticesSortedVect)
	{
		VerticesSorted.push(i);
	}

	int count = 1;
	#ifdef DEBUG_EXPANSION_TREE
	for(auto & i : VerticesSortedVect)
	{
		cout << '[' << count++ << ']' << ": " << i.NodeName << ", " << &i << endl;
	}
	cout << endl;
	#endif
}
