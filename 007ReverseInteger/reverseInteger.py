def overflow(y):
    if y > 2147483647 or y < -2147483648:
        return True
    else:
        return False

def reverse(x):
    if x < 0:
        negative = True
        x *= -1
    else:
        negative = False

    xString = str(x)

    y = 0
    for i in reversed(range(len(xString))):
        y = (y * 10) + int(xString[i])
    
    if negative:
        y *= -1
    
    if overflow(y):
        return 0
    else:
        return y
# 2147483648
print(reverse(100)) # 1
print(reverse(-1052)) # -2501
print(reverse(2147483648)) # overflow
print(reverse(-8463847412))