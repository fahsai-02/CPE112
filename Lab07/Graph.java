public class Graph{
    public static void main(String[] args) {
        AdjacencyMatrix g = new UndirectedGraph(4);
        // AdjacencyMatrix h = new DirectedGraph(4);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(1, 3);
        System.out.println(g+""+g.toString());
        System.out.println("An edge between");
        g.removeEdge(1,2);
        System.out.println(g);

        g = new UndirectedGraph(5);
        g.addEdge(3, 4);
        System.out.println(g);

        WeightedGraph g2 = new WeightedGraph(5);
        g2.addEdge(0, 1);
        g2.addEdge(0, 3, 5);
        System.out.println(g2);

    }
}
