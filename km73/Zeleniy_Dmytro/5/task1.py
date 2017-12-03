heights = []
n = int(input("Enter number of pupil: ")) 
for i in range(n):  
    new_height = int(input("Enter hight pupil less than previous: "))
    heights.append(new_height)  
height = int(input("Enter height of Petya: "))
heights.append(height)

if height < 200:
    heights.sort()
    heights = heights[::-1]
    same_height = heights.count(height)
    answer = heights.index(height) + same_height
else:
    answer = "Not correct data"

print("Place of Petya is " + str(answer))
