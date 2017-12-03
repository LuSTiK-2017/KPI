x_coord = []
y_coord = []
x_coord.append(int(input("Enter x1 coordinate: ")))
y_coord.append(int(input("Enter y1 coordinate: ")))
x_coord.append(int(input("Enter x2 coordinate: ")))
y_coord.append(int(input("Enter y2 coordinate: ")))
x_coord.append(int(input("Enter x3 coordinate: ")))
y_coord.append(int(input("Enter y3 coordinate: ")))
x_coord.append(int(input("Enter x4 coordinate: ")))
y_coord.append(int(input("Enter y4 coordinate: ")))
x_coord.append(int(input("Enter x5 coordinate: ")))
y_coord.append(int(input("Enter y5 coordinate: ")))
x_coord.append(int(input("Enter x6 coordinate: ")))
y_coord.append(int(input("Enter y6 coordinate: ")))
x_coord.append(int(input("Enter x7 coordinate: ")))
y_coord.append(int(input("Enter y7 coordinate: ")))
x_coord.append(int(input("Enter x8 coordinate: ")))
y_coord.append(int(input("Enter y8 coordinate: ")))

answer = "No"

for x in x_coord:
    if x_coord.count(x) > 1:
        answer = "Yes"
for y in y_coord:
    if y_coord.count(y) > 1:
        answer = "Yes"

for i in range(8):
    for j in range(i+1, 8):
        if (abs(x_coord[i]-x_coord[j]) == abs(y_coord[i]-y_coord[j])) or (abs(x_coord[i]-y_coord[i]) == abs(x_coord[j] == y_coord[j])):
            answer = "Yes"

print(answer)