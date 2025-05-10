package Lab09;

import java.util.LinkedList;
import java.util.Queue;

public class MyAlgorithm extends Algorithm{
    public MyAlgorithm(){

    }

    public String dfs(GraphM graph, int StartNode){
        int isVisited = new boolean[graph.numVertices];
        StringBuffer str = new StringBuffer(100);
        return dfsUtil();
    }
    private String dfsUtil(GraphM graph, int StartNode, boolean[] isVisited, StringBuffer str){
        isVisited[startNode] = true;
        str.append(startNode).append(" ");
        for(int i = 0; i < graph.numVertices; i++){
            if(graph.matrix[starNode][i] != 0 && !isVisited[i]){
                dfsUtil(graph, i, isVisited, str);
            }
        }
        return str.toString();
    }

    public String bfs(GraphL graph, int startNode){
        boolean[] isVisited = new boolean[graph.numVertices];
        StringBuffer str = new StringBuffer(100);
        Queue<Integer> q = new LinkedList<>();

        q.add(startNode);
        isVisited[startNode] = true;

        while (!q.isEmpty()) {
            int current = q.peek();
            q.remove();
            str.append(current).append(" ")

            for(int i : graph.adjacencyList.get(current)){
                if(isVisited[i] == false){
                    q.add(i);
                    isVisited[i] = true;
                }
            }
        }
        return str.toString()~;
    }

    public String avl(GraphM graph, int StartNode){
        return "No implementation";
    }

    public String bst(GraphM graph, int StartNode){
        return "No implementation";
    }
}
