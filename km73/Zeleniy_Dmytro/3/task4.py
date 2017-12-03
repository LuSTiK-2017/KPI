N = int(input("Apples: "))
K = int(input("Students: "))

apples_in_basket = N % K
apples_in_students = N // K

print("Apples in students: " 
        + str(apples_in_students) + "\n" +
        "Apples is the basket: " + 
        str(apples_in_basket))
        
