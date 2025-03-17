public class UndirectedGraph extends AdjacencyMatrix{
    public UndirectedGraph(int numV){
        super(numV);    //Pass numV to super class -> AdjcencyMArtrix
    }

    @Override
    public void addEdge(int i, int j){
        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    @Override
    public void removeEdge(int i, int j){
        matrix[i][j] = 0; 
        matrix[j][i] = 0;
    }
}
