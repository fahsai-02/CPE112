// 67070501064 Nakagamon Saengdara

package Lab08;
import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("What type of Graph? (D/U): ");
        char type = sc.next().charAt(0);
        System.out.printf("Is the graph weighted? (Y/N): ");
        boolean isWeighted = sc.next().charAt(0) == 'Y';
        
        Graph graph;
        if(type == 'D'){
            graph = new DirectedGraph(isWeighted) ;
        }else{
            graph = new UndirectedGraph(isWeighted) ;
        }

        System.out.println("How many Edge? : ");
        int E = sc.nextInt();
        
        for(int i = 0; i < E; i++){
            String src = sc.next();
            String dest = sc.next();
            if(isWeighted){
                int weight = sc.nextInt();
                graph.addEdge(src, dest, weight);
            }else{
                graph.addEdge(src, dest);
            }
        }

        System.out.println("------------------------------------------");
        System.out.println("How many node do you want to ask? : ");
        int n = sc.nextInt();
        for(int i = 0; i < n; i++ ){
            String name = sc.next();

            if (!graph.adjacencyList.containsKey(name)) {
                System.out.printf("Node '%s' does not exist in the graph.\n\n", name);
                continue;
            }

            if(type == 'D'){
                System.out.printf("Deg(+): %d\n", graph.getOutDegree(name));
                // System.out.printf("Deg(-): %d\n", graph.getInDegree(name));
                if(isWeighted){
                    System.out.printf("Weight: %d\n", graph.sumWeightOut(name));
                }
            }else{
                System.out.printf("Deg: %d\n", graph.getOutDegree(name));
                // System.out.printf("Deg(-): %d\n", graph.getInDegree(name));
                if(isWeighted){
                    System.out.printf("Weight: %d\n", graph.sumWeightOut(name));
                }
            }
        }
        sc.close();
    }

    /*
     * javac -d. *.java
     * java Lab08.Main
     */
}