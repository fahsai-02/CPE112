package Lab09;

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

    public String bfs(GraphM graph, int StartNode){
        return "No implementation";
    }

    public String avl(GraphM graph, int StartNode){
        return "No implementation";
    }

    public String bst(GraphM graph, int StartNode){
        return "No implementation";
    }
}
