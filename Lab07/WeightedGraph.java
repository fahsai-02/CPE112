public class WeightedGraph extends DirectedGraph {
    public WeightedGraph(int numV){
        super(numV);
    }

    public void addEdge(int i, int j, int val){ //   Overload
        matrix[i][j] = val;
    }

}
