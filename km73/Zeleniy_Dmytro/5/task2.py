elements = []
n = int(input("Enter number of elements: ")) 

for i in range(n):
    element = input("Enter element: ")
    elements.append(element)

counter = 0
for i in range(len(elements)-1):
    for j in range(i+1, len(elements)):
        if elements[i] == elements[j]:
            counter += 1

print("Number of pairs " + str(counter))