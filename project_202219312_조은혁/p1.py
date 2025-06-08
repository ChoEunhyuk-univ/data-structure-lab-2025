# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def bubble_sort(arr):
    """
    버블 소팅 함수
    평균을 구하는데는 정렬배열이 필요없지만, 중간값을 구하기 위해서는 필요하므로 소팅 필요.
    """
    sorted_arr = arr[:] # 원본 리스트를 변경하지 않기 위해 복사
    n = len(sorted_arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if sorted_arr[j] > sorted_arr[j+1]:
                sorted_arr[j], sorted_arr[j+1] = sorted_arr[j+1], sorted_arr[j]
    return sorted_arr

def problem1(numbers): # 매개변수명을 input에서 numbers로 변경
    '''
    평균은 input 배열을 for문으로 sum에 적산한 후, 개수로 나누면 될듯.
    중앙값은 이 input을 소팅해서 가운데 값을 리턴하면 될거같은데?
    '''
    # 평균 계산
    sum_val = 0
    for x in numbers:
        sum_val += x
    avg = sum_val / len(numbers)

    # 중앙값 계산 / bubble_sort 함수를 사용하여 리스트를 정렬
    sorted_numbers = bubble_sort(numbers)
    
    n = len(sorted_numbers)

    mid = sorted_numbers[n // 2]
    
    result = [0,0]
    
    result[0] = avg
    result[1] = mid
    return result

result = problem1(input)

assert result == [34, 30]
print("정답입니다.")
