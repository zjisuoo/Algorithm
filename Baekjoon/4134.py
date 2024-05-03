import math 

def is_prime_number(number):
    is_prime = True
    
    if number == 0 or number == 1:
        is_prime = False
    else:
        for num in range(2, int(math.sqrt(number))+1):
            if number % num == 0:
                is_prime = False
                break
                
    return is_prime

def next_primary_number(number): 
    while True:
        is_prime = is_prime_number(number=number)
        
        if is_prime:
            answer = number
            break
        number += 1
            
    return answer
            
if __name__ == "__main__":
    for _ in range(int(input())):
        number = int(input())
        print(next_primary_number(number=number))