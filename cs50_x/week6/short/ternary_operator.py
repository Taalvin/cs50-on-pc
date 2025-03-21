letters_only = True if input("Input character: ").isalpha() else False

if letters_only == True:
    print("Character is an alphabet.")
else:
    print("Character is NOT an alphabet.")