# Incomplete phonebook.

def main():
    # Sets up list.
    persons = ["nemisha", "taalvin", "sekha"]

    # Gets input from user.
    person = input("Name: ").lower()

    if person in persons:
        print("Person found")
    else:
        print("Person not found.")

main()