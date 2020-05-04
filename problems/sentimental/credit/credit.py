from cs50 import get_int

cc = get_int("Number: ")
credit_card_number = cc

sum, digits, is_other_digit = 0, 0, False
while credit_card_number != 0:
    number = credit_card_number % 10
    if is_other_digit:
        number *= 2
        if number > 9:
            first_digit = number % 10
            second_digit = number // 10
            sum += (first_digit + second_digit)
        else:
            sum += number
    else:
        sum += number
        
    digits += 1
    is_other_digit = not is_other_digit
    credit_card_number = credit_card_number // 10
    
if sum % 10 == 0:
    while cc > 100:
        cc = cc // 10
        
    if cc >= 51 and cc <= 55 and digits == 16:
        print("MASTERCARD")
    elif (cc == 34 or cc == 37) and digits == 15:
        print("AMEX")
    elif (cc >= 40 and cc <= 49) and (digits == 13 or digits == 16):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
        