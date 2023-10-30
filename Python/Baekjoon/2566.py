def max_number(number_list):
    max_num_list = []
    for row, numbers in enumerate(number_list, start=1):
        max_num = max(numbers)
        col = numbers.index(max_num) + 1

        max_num_list.append((f"{row} {col}", max_num))
            
    return max(max_num_list, key=lambda x: x[1])

if __name__ == "__main__":
    number_list = []
    
    for _ in range(9):
        numbers = list(map(int, input().split()))
        number_list.append(numbers)
        
    answer = max_number(number_list)
    
    print(answer[1])
    print(answer[0])