# 프로젝트 문제 2번
input = ")))()"

class Stack:
    """
    Stack구조 클래스로 구현

    __init__ : 스택을 초기화함
    push : 스택에 아이템을 추가함(apppend)
    pop : 스택에 마지막으로 추가된 아이템을 참조 및 제거함
    peek : 스택에 마지막으로 추가된 아이템을 참조함
    is_empty : 스택이 비었는지 체크
    size : 스택에 쌓인 자료량 갯수 반환
    """
    def __init__(self):
        """스택 초기화"""
        self._items = []

    def push(self, item):
        self._items.append(item)

    def pop(self):
        if not self.is_empty():
            return self._items.pop()

    def peek(self):
        if not self.is_empty():
            return self._items[-1]
        raise IndexError("스택이 비었습니다")

    def is_empty(self):
        return len(self._items) == 0

    def size(self):
        return len(self._items)

def problem2(input): # 함수명 변경 및 매개변수명 s로 변경
    """
    괄호갯수를 체크해주는 함수
    1)input을 차례로 분석하며 스택에 괄호를 넣음.
        -우선 검사한 input의 괄호가 여는 괄호면 스택에 추가.
        -만약 닫는 괄호면 스택을 pop해서 닫힌 괄호임을 확인함.
    2)순회 후에도 스택에 괄호가 남아있다면, 이 괄호의 갯수만큼 additions 변수에 추가함.
    3) 이 additions 변수는 괄호열 완성을 위해 필요한 갯수가 될거임.
    """
    stack = Stack() # 직접 구현한 Stack 클래스 사용
    additions = 0

    for char in input:
        if char == '(':
            stack.push(char) # 여는 괄호는 스택에 추가
        elif char == ')':
            if not stack.is_empty(): # 스택에 여는 괄호가 있으면
                stack.pop() # 짝을 맞춰 제거
            else: # 스택에 여는 괄호가 없으면
                additions += 1 # 닫는 괄호에 대응할 여는 괄호가 필요하므로 추가 카운트
            
    # 문자열 순회 후 스택에 남아있는 여는 괄호의 수만큼 닫는 괄호가 필요
    additions += stack.size() # 스택의 크기만큼 추가
    return additions

result = problem2(input)
assert result == 3
print("정답입니다.")
