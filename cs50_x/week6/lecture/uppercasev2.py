# Showcases loop in python.

# Gets string from user.
string = input("string: ")

# Prints result.
print("Uppercased string: ", end="")
for i in string:
    print(i.upper(), end="")
print()
