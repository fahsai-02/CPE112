import java.util.Scanner;

class Node {
    int key, height;
    Node left, right;

    Node(int value) {
        key = value;
        height = 1;
    }
}

class AVLTree {
    Node root;

    public Node rightRotate(Node oldRoot) {
        Node newRoot = oldRoot.left;
        Node T2 = newRoot.right;

        newRoot.right = oldRoot;
        oldRoot.left = T2;

        oldRoot.height = Math.max(height(oldRoot.left), height(oldRoot.right)) + 1;
        newRoot.height = Math.max(height(newRoot.left), height(newRoot.right)) + 1;

        return newRoot;
    }

    public Node leftRotate(Node oldRoot) {
        Node newRoot = oldRoot.right;
        Node T2 = newRoot.left;

        newRoot.left = oldRoot;
        oldRoot.right = T2;

        oldRoot.height = Math.max(height(oldRoot.left), height(oldRoot.right)) + 1;
        newRoot.height = Math.max(height(newRoot.left), height(newRoot.right)) + 1;

        return newRoot;
    }

    public int height(Node node) {
        if (node == null) return 0;
        return node.height;
    }

    public int balanceFactor(Node node) {
        if (node == null) return 0;
        return height(node.left) - height(node.right);
    }

    public Node insert(Node node, int key) {
        if (node == null) return new Node(key);

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        } else {
            return node;
        }

        node.height = 1 + Math.max(height(node.left), height(node.right));

        int balanceFactor = balanceFactor(node);

        if (balanceFactor > 1 && key < node.left.key) {
            return rightRotate(node);
        }

        if (balanceFactor < -1 && key > node.right.key) {
            return leftRotate(node);
        }

        if (balanceFactor > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balanceFactor < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    public void preorder(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

    public void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.key + " ");
            inorder(root.right);
        }
    }

    public void postorder(Node root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right); 
            System.out.print(root.key + " ");
        }
    }

    // public void printTree(Node root, String indent, boolean isLeft) {
    //     if (root != null) {
    //         System.out.println();
    //     }
    // }

    // public void displayTree() {
    //     printTree(root, "", false);
    // }
}

public class Lab07_AVLTree {
    public static void main(String[] args) {
        AVLTree tree = new AVLTree();
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter elements: ");
        for (int i = 0; i < n; i++) {
            int input = sc.nextInt();
            tree.root = tree.insert(tree.root, input);
        }
        sc.close();

        System.out.println("\nPreorder traversal:");
        tree.preorder(tree.root);
        System.out.println();

        System.out.println("Inorder traversal:");
        tree.inorder(tree.root);
        System.out.println();

        System.out.println("Postorder traversal:");
        tree.postorder(tree.root);
        System.out.println();

        // System.out.println("\nTree structure:");
        // tree.displayTree();
    }
}
