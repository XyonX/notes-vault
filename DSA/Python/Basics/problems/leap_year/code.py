#leap year logic 
#if divisible by 400 ,and if divisble by 100 its not leap year but if divisible by 4 its leap year and in other case not leapyear
def is_leap(year):
    leap = False
    
    # Write your logic here
    if year%400 == 0:
        return True
    elif year%100 ==0:
        return False
    elif year%4 ==0:
        return True
    else:
        return False
    
    return leap