package Lab09;

import java.util.ArrayList;

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

    public void addvertex(int ver){
        this.adjacencyList.put(ver, new ArrayList<>()) ;
    }
    public void addEdge(int src, int dest){
        this.adjacencyList.get(src).add(dest)   //.get = accass list, add = insert value
        if(this.isDirected == false){
            this.adjacencyList.get(dest).add(src);
        }
    }
}
