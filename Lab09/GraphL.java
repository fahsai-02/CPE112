package Lab09;

public class GraphL extends AdjL {
    boolean isDirected;
    int numVertices;
    int numEdges;

    public GraphL(boolean isDirected, int numVertices, int numEdges){
        super();
        this.isDirected = isDirected;
        this.numEdges = numEdges;
        this.numVertices = numVertices;
    }

    public void addvertex(int ver);
    public void addEdge(int src, int dest);
}
