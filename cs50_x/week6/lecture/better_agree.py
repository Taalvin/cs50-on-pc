# Gets input from user.
choice = input("Do you agree?[y/n] ").lower()

# Prints result.
if choice in ["y", "yes"]:
    print("User has agreed.")
elif choice in ["n", "no"]:
    print("User has NOT agreed.")