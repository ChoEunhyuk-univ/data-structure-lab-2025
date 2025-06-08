class queue:
    """
    BFS 탐색을 위해 Queue구조 정의.
    isEmpty : 큐가 비어있는지 점검
    enqueue : 큐 뒤에 값 추가
    dequeue : 큐 앞의 값 참조 및 대기열에서 삭제
    size : 큐의 크기 재기(저장된 값 개수 반환)
    """
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0,item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

class Stack:
    """
    DFS 탐색을 위해 Stack구조 정의.
    isEmpty : 스택이 비어있는지 점검
    push(item) : 스택에 값(item) 추가
    pop : 스택에 가장 최근에 추가된 값 반환 및 구조에서 제거
    peek : 스택에 가장 최근에 추가된 값 반환
    __bool__(): 스택이 비어있지 않으면 True를, 비어있으면 False를 반환함.
                이 메소드 덕분에 `while stack:`과 같이 스택 객체를 직접 불리언 컨텍스트에서 사용할 수 있음.
    """
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []
    
    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.isEmpty():
            return self.items.pop()
        return None

    def peek(self):
        if not self.isEmpty():
            return self.items[-1]
        return None
    
    def __bool__(self):
        return not self.isEmpty()


A = {
    0: [1, 2, 3],
    1: [0, 2, 4, 5],
    2: [0, 1, 6],
    3: [0],
    4: [1],
    5: [1],
    6: [2]
}

def bfs(A):
    answer = [] # BFS 결과 저장
    '''
    bfs / 너비 우선 탐색

    1)노드 0을 큐에 넣고 방문 처리함(visited = true)
    2)이웃한 노드들을 작은 숫자 순으로 큐에 추가함.
    3)큐에서 반환된 노드를 방문하며 방문 처리 및 이웃 노드 큐에 추가.
    4)2~3 과정을 반복.
    
    최종적으로 각 노드는 얕은 레벨에 있는 순서대로 탐색됨.
    
    Args : 
        A(dict) : 인접 리스트로 표현된 그래프.
    
    Returns :
        list : BFS 방문 순서대로 노드들을 담은 리스트.
    '''
    q = queue() # BFS 큐
    if not A:
        return [] # 빈 그래프면 종료
    
    # 모든 노드 파악 및 노드 수 계산
    all_nodes = set(A.keys())
    for neighbors_list in A.values():
        for node in neighbors_list:
            all_nodes.add(node)
    
    if not all_nodes: 
        if 0 in A: num_nodes = 1 
        else: return [] 
    else:
        num_nodes = max(all_nodes) + 1

    visited = [False] * num_nodes # 방문 기록
    start_node = 0 # 시작점 0으로 선언

    if start_node >= num_nodes:
        return [] # 시작점 오류면 종료

    # 시작 노드 처리
    q.enqueue(start_node)
    visited[start_node] = True

    while not q.isEmpty(): # 큐 탐색
        # 현재 노드 방문
        current_node = q.dequeue()
        answer.append(current_node)

        if current_node in A:
            # 이웃 노드들 큐에 추가
            for neighbor in A[current_node]:
                if neighbor < num_nodes and not visited[neighbor]:
                    visited[neighbor] = True
                    q.enqueue(neighbor)

    return answer


def dfs(A):
    """dfs / 깊이 우선 탐색

    그래프 A를 스택을 활용하여 DFS.

    1) 시작 노드(0)를 스택에 넣고 방문 처리.
    2)스택에서 노드를 하나 꺼내 방문 순서 리스트(`answer`)에 추가함.
    3)꺼낸 노드의 이웃 노드들을 확인함. 작은 번호의 이웃을 먼저 방문하기 위해,
    이웃 리스트를 역순으로(큰 번호부터) 스택에 추가함.
    이때 아직 방문하지 않은 이웃만 스택에 추가하고 방문 처리.
    4)다음 노드 방문
    5)2~4 과정을 반복.

    Args:
        A (dict): 인접 리스트로 표현된 그래프. 키는 노드를, 값은 해당 노드의 이웃 노드 리스트를 나타냄.
    Returns:
        list: DFS 방문 순서대로 노드들을 담은 리스트. 그래프가 비어있거나 시작 노드가 유효하지 않으면 빈 리스트를 반환.
    """
    answer = [] # DFS 결과 저장
    stack = Stack() # DFS 스택
    if not A:
        return [] # 빈 그래프면 종료
    
    # 모든 노드 파악 및 노드 수 계산
    all_nodes = set(A.keys())
    for neighbors_list in A.values():
        for node in neighbors_list:
            all_nodes.add(node)
    
    if not all_nodes: 
        if 0 in A: num_nodes = 1
        else: return []
    else:
        num_nodes = max(all_nodes) + 1

    visited = [False] * num_nodes # 방문 기록
    start_node = 0 # 시작점 0으로 선언

    if start_node >= num_nodes:
        return [] # 시작점 오류면 종료

    # 시작 노드 처리
    stack.push(start_node)
    visited[start_node] = True

    while stack: # 스택 탐색
        # 현재 노드 방문
        current_node = stack.pop()
        answer.append(current_node)

        if current_node in A:
            # 이웃 노드들 스택에 추가 (작은 번호 우선)
            for neighbor in reversed(A[current_node]):
                if neighbor < num_nodes and not visited[neighbor]:
                    visited[neighbor] = True
                    stack.push(neighbor)

    return answer

bfs_result = bfs(A) 
dfs_result = dfs(A) 

assert bfs_result == [0,1,2,3,4,5,6] # BFS 검증
assert dfs_result == [0,1,4,5,2,6,3] # DFS 검증
print('PASSED!')
