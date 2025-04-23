// 67070501064 Nakagamon Saengdara

package Lab08;
import java.util.*; //(list)

public abstract class Graph {   
    protected int numVertices;
    protected Map<String, List<Edge>> adjacencyList;
    protected boolean isWeighted;

    public Graph(boolean isWeighted){
        this.numVertices = 0 ;
        this.isWeighted = isWeighted;
        this.adjacencyList = new HashMap<>();
    }

    protected void addNode(String name){
        if(!adjacencyList.containsKey(name)){
            adjacencyList.put(name, new ArrayList<>());
        }
    }
    // for unweigted graph
    public boolean addEdge(String source, String destination){
        if(!isWeighted){
            addEdgeWithWeight(source, destination, -1);
            return true;
        }else{
            return false;
        }
    }
    // for weighted graph
    public boolean addEdge(String source, String destination, int weight){
        if(isWeighted){
            addEdgeWithWeight(source, destination, weight);
            return true;
        }else{
            return false;
        }
    }

    public int getOutDegree(String name){
        return adjacencyList.get(name).size();
    }

    public int getInDegree(String name){
        int inDegree = 0;
        for(List<Edge> linkEdges : adjacencyList.values()){
            for(Edge edge : linkEdges){
                if(edge.destination.equals(name)){
                    inDegree++;
                }
            }
        }
        return inDegree;
    }

    public int sumWeightOut(String name){
        int sum = 0;
        for(Edge edge : adjacencyList.get(name)){
            sum += edge.weight;    
        }
        // sum = adjacencyList.getOrDefault(name, Collections.emptyList())
        // .stream().mapToInt(edge -> edge.weight).sum();
        return sum;

    }

    public int sumWeightIn(String name){
        int sum = 0;
        for(List<Edge> linkEdges : adjacencyList.values()){
            for(Edge edge : linkEdges){
                if(edge.destination.equals(name)){
                    sum += edge.weight;
                }
            }
        }
        return sum;
    }
    
    protected abstract void addEdgeWithWeight(String source, String destination, int weight);

}
