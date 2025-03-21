# Searches for a name in a phonebook.

def main():
    # Initializing phonebook.
    phonebook = {
        "nemisha" : "+230-5822-4982",
        "taalvin" : "+230-5503-5669",
        "sekha"   : "+230-5504-8298"
    }

    # Gets name from the user.
    name = input("Name: ").lower()

    # Prints result.
    if name in phonebook:
        print(f"Number: {phonebook[name]}")
    else:
        print("person was NOT found.")


main() 