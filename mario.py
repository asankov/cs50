
def main():
    n = get_number(1, 8)
    
    for i in range(n):
        for j in range(n-i-1):
            print(" ", end="")
        
        print("#"*(i+1), end="")
        
        print("  ", end="")
        
        print("#"*(i+1), end="")

            
        print()


def get_number(min, max):
    n = min-1
    while n < min or n > max:
        try:
            n = int(input("Height: "))
        except ValueError:
            continue
    return n
    
main()