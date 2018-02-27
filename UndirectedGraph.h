#ifndef __UNDIRECTEDGRAPH_H
#define __UNDIRECTEDGRAPH_H
template <class TVertex>
class UndirectedGraph
{
private:
	 bool allowParallelEdges;
	 int edgeCount;
	 std::map<TVertex, std::vector<TVertex>* > edges;
	 bool AddVerticesAndEdgeStraight(Edge<TVertex> edge);
	 
public:
	
	UndirectedGraph();
	UndirectedGraph(bool allowParallelEdges);
	int VertexCount();
	std::vector<TVertex> Vertices();
	int EdgeCount();
	std::vector<Edge<TVertex> > Edges();
	std::vector<TVertex> GetNeighbors(TVertex vertex);
	std::vector<TVertex> GetNodesSortedByDegree(int count);
	std::vector<int> GetReverseDegreeSequence();
	std::map<TVertex, std::vector<TVertex> > Clone();
	std::string ToString();
	bool RemoveVertex(TVertex v);
	void Clear();
	void ClearAdjacentEdges(TVertex v);
	bool TryGetEdge(TVertex source, TVertex target, Edge<TVertex> *edge);
	bool ContainsEdge(TVertex source, TVertex target);
	bool AddVerticesAndEdge(TVertex source, TVertex target);
	bool AddVerticesAndEdge(Edge<TVertex> edge);
	int AddVerticesAndEdgeRange(std::iterator<Edge<TVertex>, std::input_iterator_tag> edges);
	int GetDegree(TVertex v);
	
	
};

#include "UndirectedGraph.cpp.h"
#endif