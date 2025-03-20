package Lab08;

public class UndirectedGraph extends Graph {
    public UndirectedGraph(boolean isWeighted){
        super(isWeighted);
    }
    
    @Override
    protected void addEdgeWithWeight(String source, String destination, int weight){
        addNode(source);
        addNode(destination);
        adjacencyList.get(source).add(new Edge(destination, weight));
        adjacencyList.get(destination).add(new Edge(source, weight));
    }
    /*
     * "A": [Edge("B", 5), Edge("C", 2)],
     * "B": [Edge("A", 5), Edge("C", 3)]
     * "C": [Edge("C", 2), Edge("B", 3)]
     */
}
