package yeonho.Week_17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class P5639_binarySearchTree {

    static class Node {
        int key;
        Node left, right;

        Node(int key) {
            this.key = key;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> preOrder = new ArrayList<>();
        String line;

        // 입력된 전위 순회 결과를 리스트에 저장
        while ((line = br.readLine()) != null && !line.isEmpty()) {
            preOrder.add(Integer.parseInt(line));
        }

        // 트리 생성
        Node root = buildTree(preOrder, 0, preOrder.size() - 1);

        // 후위 순회 결과 출력
        StringBuilder sb = new StringBuilder();
        postOrderTraversal(root, sb);
        System.out.print(sb.toString());
    }

    // 이진 검색 트리 생성 (재귀적으로 처리)
    static Node buildTree(List<Integer> preOrder, int start, int end) {
        if (start > end)
            return null;

        // 첫 번째 값이 현재 서브트리의 루트
        Node root = new Node(preOrder.get(start));

        // 루트보다 큰 값이 처음으로 나타나는 위치 찾기
        int splitIndex = start + 1;
        while (splitIndex <= end && preOrder.get(splitIndex) < root.key) {
            splitIndex++;
        }

        // 왼쪽 서브트리와 오른쪽 서브트리를 재귀적으로 생성
        root.left = buildTree(preOrder, start + 1, splitIndex - 1);
        root.right = buildTree(preOrder, splitIndex, end);

        return root;
    }

    // 후위 순회 (재귀적으로 처리)
    static void postOrderTraversal(Node node, StringBuilder sb) {
        if (node == null)
            return;

        // 왼쪽, 오른쪽, 루트 순으로 탐색
        postOrderTraversal(node.left, sb);
        postOrderTraversal(node.right, sb);
        sb.append(node.key).append("\n");
    }
}
