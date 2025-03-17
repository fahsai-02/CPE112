public class DirectedGraph extends AdjacencyMatrix {
    public DirectedGraph(int numV){
        super(numV);
    }
    @Override
    public void addEdge(int i, int j){
        matrix[i][j] = 1;

    }
    @Override
    public void removeEdge(int i, int j){
        matrix[i][j] = 0;
    }
}
