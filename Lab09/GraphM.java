package Lab09;
// อันนี้ให้เขียนเอง
public class GraphM extends AdjM {
    int numVertices;
    boolean isDirected;

    public GraphM(int n, boolean isDirected){
        super(n);
        this.numVertices = n;
        this.isDirected = isDirected;
    }

    public void addEdge(int i,int j, int weight){
        this.matrix[i][j] = weight;
        if(!isDirected){
            this.matrix[j][i] = weight;
        }
    }

    public abstract void getWeight(int i,int j){
        return this.martrix[i][j];
    }
}
