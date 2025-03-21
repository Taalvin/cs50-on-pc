# Appends list_2 to list_1.

list_1 = [1, 2, 3, 4]
list_2 = [5, 6, 7, 8]

list_1[len(list_1):] = list_2

print(list_1)