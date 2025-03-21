# Gets user input.
choice = input("Do you agree?[y/n] ")

# prints results.
if choice == "y" or choice == "Y":
    print("User has agreed.")
elif choice == "n" or choice == "N":
    print("User has NOT agreed.")