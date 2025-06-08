# 프로젝트 문제 2번
input = ")))()"

def problem2(input): # 매개변수명을 input에서 input로 변경하여 내장 함수 input과의 혼동을 피했습니다.
    # 이 곳에 코드를 작성하세요. (주석에 따라 아래 로직으로 구현)
    """
    스택으로 palindrome check하면 될거같은데?
    스택으로 괄호를 넣고, 만약 (면 판단자에 +1, )면 -1 이런식으로 해서
    판단자가 0이 될때까지 이걸 반복해도 되지 않을까?

    근데 그러면 순서가 꼬이지 않음? -> ㄴㄴ. 그건 그냥 닫힌 괄호라 상관없어짐. 저렇게 해서, 모자란 수만큼 자료구조에 append 시켜주면 될거같음.
    list 방식이면 앞에 insert고, 만약 스택이라면, 한번 검사한다고 만든 검사용 스택에 그냥 append 하면 될거같음.
    """
    # 입력 힌트
    balance = 0  # 주석의 '판단자' 역할
    additions = 0 # 추가해야 할 괄호의 수

    for char in input:
        if char == '(':
            balance += 1
        elif char == ')':
            balance -= 1
        
        # 판단자가 음수가 되면, 닫는 괄호 ')'가 여는 괄호 '('보다 먼저 나온 경우입니다.
        # 이 경우, 여는 괄호 '('를 하나 추가해야 합니다.
        if balance < 0:
            additions += 1
            balance += 1 # 추가된 '('를 반영하여 판단자를 조정합니다.
            
    # 문자열 순회가 끝난 후, 판단자가 양수이면 그만큼 여는 괄호 '('가 많다는 의미입니다.
    # 따라서, 부족한 닫는 괄호 ')'를 추가해야 합니다.
    if balance > 0:
        additions += balance
            
    return additions

result = problem2(input)

assert result == 3
print("정답입니다.")
