import java.util.Scanner;

class Node {
    int data;
    String name;
    Node left;
    Node right;

    public Node(int data, String name) {
        this.data = data;
        this.name = name;
        this.left = null;
        this.right = null;
    }
    // กำหนดลูกให้โหนดปัจจุบัน
    public boolean setChildNode(Node child, char direction) {
        if (direction == 'L') {
            this.left = child;
            return true;
        } else if (direction == 'R') {
            this.right = child;
            return true;
        }
        return false;
    }
}

class Tree {
    Node[] node;    // เก็บโหนดทั้งหมด
    Node root;
    int size = 0;   // ติดตามจำนวนโหนดที่ถูกสร้าง

    public Tree(int n) {
        this.node = new Node[n];    // กำหนดขนาด array
        this.root = null;
    }

    private Node searchByName(String name) {
        for (Node n : this.node) {
            if (n != null && n.name.equals(name)) {
                return n;
            }
        }
        return null;
    }

    public boolean addNode(String name, int data) {
        if (size < node.length) {
            node[size++] = new Node(data, name);
            return true;
        }
        return false;
    }

    public boolean addEdge(String pName, String cName, char direction) {
        Node pNode = searchByName(pName);
        Node cNode = searchByName(cName);

        if (pNode == null || cNode == null) {
            return false;
        } else {
            return pNode.setChildNode(cNode, direction);
        }
    }

    public boolean setRoot(String rName) {
        Node rootNode = searchByName(rName);
        if (rootNode != null) {
            this.root = rootNode;
            return true;
        }
        return false;
    }

    private void preorder(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    private void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }

    private void postorder(Node root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data + " ");
        }
    }

    public void preorder() {
        preorder(this.root);
        System.out.println();
    }

    public void inorder() {
        inorder(this.root);
        System.out.println();
    }

    public void postorder() {
        postorder(this.root);
        System.out.println();
    }
}

public class Lab05_PlantingTree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();   // รับจำนวน Node (ทิ้ง \n ไว้)
        sc.nextLine();   // ข้ามบรรทัดที่รับค่า จำนวน Node 

        Tree tree = new Tree(n);

        // รับข้อมูลของโหนด
        for (int i = 0; i < n; i++) {
            String name = sc.next();
            int data = sc.nextInt();
            sc.nextLine();
            tree.addNode(name, data);
        }

        // รับข้อมูลการเชื่อมโยง
        for (int i = 0; i < n - 1; i++) {
            String pName = sc.next();
            String cName = sc.next();
            char direction = sc.next().charAt(0);
            sc.nextLine();
            tree.addEdge(pName, cName, direction);
        }

        // กำหนด root
        String rootName = sc.next();
        tree.setRoot(rootName);

        // เรียงลำดับการเดินแบบต่างๆ
        tree.preorder();
        tree.inorder();
        tree.postorder();

        sc.close();
    }
}
