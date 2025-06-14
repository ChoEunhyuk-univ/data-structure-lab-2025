# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []
#여기에서부터 코드를 작성하세요.
# Queue 클래스 정의
class Queue:
    """
    Queue 클래스
    __init__ : 큐 초기화
    enqueue : 큐 뒤쪽에 아이템 추가
    dequeue : 큐 앞쪽에서 아이템 반환 및 제거
    is_empty : 비었는지 확인
    """
    def __init__(self):
        self._items = []
    def enqueue(self, item):
        self._items.append(item)
    def dequeue(self):
        if not self.is_empty():
            return self._items.pop(0)
        raise IndexError("큐에 아무것도 없어서 비울 수 없습니다")
    def is_empty(self):
        return len(self._items) == 0

def problem3(input_grid):
    """
    문제의 조건:
    1) 곰은 자신의 크기와 동일한 만큼 벌집을 먹으면 +1됨.
    2) 이동에는 1초가 소요됨.
    3) 따라서, 곰이 상위 벌집을 먹기 위해서는 낮은 단계의 벌집부터 먼저 털어야함.
    가정 : 곰은 벌집의 위치와 크기를 다 알고 있다. / 그래야 해당 노드로 이동 가능하므로.
    
    최종정리 :
    곰의 초기 크기는 2이고, 위치는 [2][2]이다. 한 칸 이동할때마다 시간이 1씩 추가된다.
    이제 input 2차원 리스트를 수정하는 일이 없도록 복제 리스트 forest를 만든다. 그 이후 BFS를 방문 가능한 벌집이 없을 때까지 반복하는데, BFS의 과정은 다음과 같다.
    1) 가장 가까운 벌집 탐색
     -현재 위치에서 BFS를 시작하여 먹을 수 있는 가장 가까운 벌집 탐색. 먹을 수 있는 조건은 벌집크기 < 곰 크기, 이동 가능한 조건은 벌집크기 <= 곰 크기. 탐색을 하며 큐 구조에는 벌집의 행/열/현재 위치에서의 거리를 저장함.
    2) 최종 먹이 결정
     -먹을 수 있는 후보 먹이가 없다면 총 이동 시간을 반환하고 종료.
     -먹이가 여러 개일 경우 이동할 벌집을 정함. / 거리가 짧은지를 최우선으로, 만약 거리가 같다면 행 번호가 작은 노드를 우선시함.
    3) 이동 및 흡수
     -곰의 위치를 목표 지점(먹이)로 갱신.
     -초기 논리에 따라 누적 벌집 크기 = 곰 크기이면 곰크기+1. 누적 벌집크기 0으로 리셋.
    위 과정을 흡수 가능한 벌집이 없을때까지 반복한다. 더 이상 없다면 총 이동시간을 반환.
    """
    N = len(input_grid)
    for i in range(N):
        original_row = input_grid[i] 
        copied_row = original_row[:]
        forest.append(copied_row)

    bear_size = 2      # 곰의 크기는 2에요
    eaten_for_growth = 0 # 성장을 위해 먹은 벌집 수에요. 누적값임.
    total_time = 0
    bear_r, bear_c = -1, -1
    
    # 곰의 초기 위치 찾기
    for r_idx in range(N):
        for c_idx in range(N):
            if forest[r_idx][c_idx] == 9:
                bear_r, bear_c = r_idx, c_idx
                forest[r_idx][c_idx] = 0 # 곰이 있던 자리는 빈칸으로
                break
        if bear_r != -1: # 곰을 찾았으면 외부 루프도 종료
            break

    while True:
        # BFS를 사용하여 먹을 수 있는 가장 가까운 벌집 찾기
        # q 내부 요소: (행, 열, 현재까지의 거리)
        q_bfs = Queue() # 직접 구현한 Queue 사용
        q_bfs.enqueue((bear_r, bear_c, 0))
        # visited_bfs 내부 요소: (행, 열) - 현재 BFS 탐색에서 방문한 노드 기록
        visited_bfs = set([(bear_r, bear_c)])
        
        candidate_targets = [] # (거리, 행, 열) 형태로 저장될 후보들
        min_dist_to_target = float('inf') # 현재 BFS에서 찾은 가장 가까운 먹이까지의 거리
        while not q_bfs.is_empty(): # Queue의 is_empty() 사용
            curr_r, curr_c, dist = q_bfs.dequeue() # Queue의 dequeue() 사용

            # 이미 찾은 가장 가까운 먹이보다 더 멀리 탐색할 필요는 없음
            # (dist + 1)은 다음 이동할 칸까지의 거리임
            if candidate_targets and dist + 1 > min_dist_to_target:
                continue

            # 탐색 방향: 상, 하, 좌, 우 (문제의 우선순위: 거리 -> 행 -> 열 순이므로, 탐색 순서는 최종 정렬로 해결)
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]: # 위, 아래, 왼쪽, 오른쪽 순으로 탐색
                next_r, next_c = curr_r + dr, curr_c + dc
                
                # 격자 범위 확인 및 방문 여부 확인
                if 0 <= next_r < N and 0 <= next_c < N and (next_r, next_c) not in visited_bfs:
                    # 곰이 지나갈 수 있는 경우 (벌집 크기가 곰 크기보다 작거나 같은 경우)
                    if forest[next_r][next_c] <= bear_size:
                        visited_bfs.add((next_r, next_c))
                        
                        # 먹을 수 있는 벌집인 경우 (0 < 벌집 크기 < 곰 크기)
                        if 0 < forest[next_r][next_c] < bear_size:
                            current_target_dist = dist + 1
                            if current_target_dist < min_dist_to_target:
                                min_dist_to_target = current_target_dist
                                candidate_targets = [(min_dist_to_target, next_r, next_c)]
                            elif current_target_dist == min_dist_to_target:
                                candidate_targets.append((min_dist_to_target, next_r, next_c))
                        
                        # 다음 탐색을 위해 큐에 추가 (먹을 수 없어도 지나갈 수 있으면 추가)
                        # 단, 이미 찾은 최소 거리보다 멀어지는 경로는 더 탐색할 필요 없음
                        if not candidate_targets or (dist + 1 <= min_dist_to_target):
                            q_bfs.enqueue((next_r, next_c, dist + 1)) # Queue의 enqueue() 사용
        
        if not candidate_targets:   
            break # 먹을 수 있는 벌집이 더 이상 없음

        # 우선순위에 따라 정렬: 거리 -> 행 -> 열
        candidate_targets.sort() # 거리, 행, 열 순으로 정렬
        
        chosen_dist, chosen_r, chosen_c = candidate_targets[0]
        
        # 곰 이동 및 벌집 먹기
        total_time += chosen_dist
        bear_r, bear_c = chosen_r, chosen_c
        forest[bear_r][bear_c] = 0 # 벌집 먹음
        
        eaten_for_growth += 1
        if eaten_for_growth == bear_size:
            bear_size += 1
            eaten_for_growth = 0
            
    return total_time

result = problem3(input)

assert result == 14
print("정답입니다.")
