// 67070501064 Nakagamon Saengdara

package Lab08;

public class DirectedGraph extends Graph  {
    public DirectedGraph(boolean isWeighted){
        super(isWeighted);
    }
    
    @Override
    protected void addEdgeWithWeight(String source, String destination, int weight){
        addNode(source);
        addNode(destination);
        adjacencyList.get(source).add(new Edge(destination, weight));
    }
    /*
     * "A": [Edge("B", 5), Edge("C", 3)],
     * "B": [Edge("C", 2)],
     * "C": []
     */
}
