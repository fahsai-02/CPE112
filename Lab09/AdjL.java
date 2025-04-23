package Lab09;
import java.util.*; //HashMap

public abstract class AdjL {
    protected Map<Integer, List<Integer>> adjacencyList;    // Integer-> Key

    public AdjL(){
        this.adjacencyList = new HashMap<>();
    }

    public abstract void addvertex(int ver);
    public abstract void addEdge(int src, int dest);

}
