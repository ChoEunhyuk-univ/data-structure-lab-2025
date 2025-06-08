import sys
from collections import deque # BFS를 위한 deque 임포트

## 입력 받는 코드입니다. 수정할 필요 없습니다.
sys.stdin = open('case.txt')
N, M = list(map(int,input().split()))
# print(N, M) # N: 행의 수, M: 열의 수
concerts = []
for v in range(N):
    values = list(map(int, input().split()))
    concerts.append(values)
def count_stages(concerts):
    """콘서트 무대(0으로 표시된 영역) 개수를 세는 함수.

    주어진 2D 리스트 concerts에서 0으로 표시된 연결된 영역, 즉 '무대'가
    총 몇 개인지 찾음. BFS(너비 우선 탐색)를 사용해서 각 무대 영역을 식별하고,
    이미 센 무대는 다시 세지 않도록 visited 배열로 관리함.

    1) 입력 concerts가 비었으면 0을 바로 반환.
    2) 행렬의 모든 값이 0 또는 1인지 확인함. 아니면 ValueError 발생시킴.
       (참고: 코드 내 sys.exit(1)은 raise ValueError 이후에는 실행되지 않아 불필요함)
    3) visited 배열 (방문 기록용) 만들고, stage_count (무대 개수) 0으로 시작.
    4) 행렬의 모든 칸을 하나씩 살펴봄:
       - 만약 현재 칸이 0이고 아직 방문 안 한 곳이면:
         - stage_count 하나 올림 (새 무대 발견!).
         - 현재 칸에서 BFS 시작해서 연결된 모든 0들을 찾고 visited에 표시.
           - 큐를 사용해서 현재 칸을 넣고 방문 처리.
           - 큐가 빌 때까지 반복:
             - 큐에서 칸을 하나 꺼냄.
             - 꺼낸 칸의 상, 하, 좌, 우 인접 칸을 확인.
             - 인접 칸이 행렬 범위 안에 있고, 0이며, 아직 방문 안 했으면 방문 처리하고 큐에 추가.
    5) 다 세면 stage_count 반환.

    Args:
        concerts (list of list of int): 2차원 무대 배치도. 0은 무대, 1은 그 외.
                                        예시: [[1,0,0], [0,1,0]]

    Returns:
        int: 찾아낸 무대 영역의 총 개수.
             만약 입력 행렬에 0이나 1이 아닌 값이 있으면 ValueError가 발생함.
    """
    if not concerts or not concerts[0]:
        return 0

    # 입력값 검증: 행렬의 모든 요소가 0 또는 1인지 확인하기 / 반복문으로 검증하기
    for r_idx, row_val in enumerate(concerts):
        for c_idx, val in enumerate(row_val):
            if val not in (0, 1):
                raise ValueError("행렬에 0과 1 외의 다른 숫자가 존재.")

    rows = len(concerts)
    cols = len(concerts[0])
    visited = [[False for _ in range(cols)] for _ in range(rows)]
    stage_count = 0

    # 이동 방향 (상, 하, 좌, 우)
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    for r in range(rows):
        for c in range(cols):
            # 현재 칸이 0이고 아직 방문하지 않았다면 새로운 무대(영역) 발견
            if concerts[r][c] == 0 and not visited[r][c]:
                stage_count += 1
                q = deque() # BFS를 위한 큐
                q.append((r, c))
                visited[r][c] = True

                while q:
                    curr_r, curr_c = q.popleft()

                    # 4방향 탐색
                    for i in range(4):
                        next_r, next_c = curr_r + dr[i], curr_c + dc[i]

                        # 행렬 범위 체크
                        if 0 <= next_r < rows and 0 <= next_c < cols:
                            # 다음 칸이 0이고 아직 방문하지 않았다면
                            if concerts[next_r][next_c] == 0 and not visited[next_r][next_c]:
                                visited[next_r][next_c] = True
                                q.append((next_r, next_c))
    return stage_count

# 결과 확인을 위한 코드
# 실제 제출 시에는 문제의 요구사항에 맞게 print문을 사용하거나 제거하세요.
result = count_stages(concerts)
print(result)