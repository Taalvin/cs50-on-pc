# Complete phonebook.

def main():
    # Sets up a list of dictionaries.
    phonebook = [
        {"name" : "nemisha", "number" : "+230-5822-4982"},
        {"name" : "taalvin", "number" : "+230-5503-5669"},
        {"name" : "sekha",   "number" : "+230-5504-8298"},
    ]

    # Gets input from user.
    person = input("Name: ").lower()

    for i in phonebook:
        if i["name"] == person:
            print(f"Number: {i['number']}")
            break
    else:
        print("Person not found.")

main()