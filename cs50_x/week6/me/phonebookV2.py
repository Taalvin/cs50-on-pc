# Complete phonebook.

def main():
    # Sets up a dictionary.
    phonebook = {
        "nemisha" : "+230-5822-4982",
        "taalvin" : "+230-5503-5669",
        "sekha"   : "+230-5504-8298"
    }

    # Gets input from user.
    person = input("Name: ").lower()

    if person in phonebook:
        print(f"Number: {phonebook[person]}")
    else:
        print("Person not found.")

main()