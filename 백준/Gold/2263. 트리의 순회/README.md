# [Gold II] 트리의 순회 - 2263 

[문제 링크](https://www.acmicpc.net/problem/2263) 

### 성능 요약

메모리: 7100 KB, 시간: 1200 ms

### 분류

트리, 분할 정복, 재귀

### 문제 설명

<p>n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 n(1 ≤ n ≤ 100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.</p>

### 출력 

 <p>첫째 줄에 프리오더를 출력한다.</p>

### 풀이
후위 순회의 마지막 원소는 항상 가장 상위 root노드이다. inorder에서 root 를 찾으면 그 왼쪽이 left sub tree, 오른쪽이 right sub tree에 있는 노드들이 된다.   
inorder에서 각 서브트리의 개수를 알아내어 다시 post에 가서 left, right 를 나누고 이 서브트리에 대해 다시 재귀함수를 돌린다.   
post에서 서브트리 부분의 가장 오른쪽 원소 또한 그 해당 서브트리의 root 노드가 된다.   
이런식으로 분할정복 코드를 짜서 preorder 을 구할 수 있다. 
