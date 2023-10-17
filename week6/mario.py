from cs50 import get_int


max = 8
min = 1
height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")
if height <= 8 and height >= 1:
    i = 0
    while i < height:
        j = 1
        while j < (height - i):
            print(" ", end="")
            j += 1
        k = height
        while k > (height - i):
            print("#", end="")
            k -= 1
        print("#")
        i += 1