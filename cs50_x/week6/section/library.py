# Simple program that lets user search an author of a specific
# book from a library.

def main():
    # Creating a list of dictionaries called library.
    library = [
    {
        "title" : "Reverend Insanity", 
        "author" : "Gu Zhen Ren"
    },
    {
        "title" : "H.I.V.E", 
        "author" : "Mark Walden" 
    },
    {
        "title" : "C programming: A modern approach", 
        "author" : "K. N King"
    }
    ]

    # Gets book title from standard input.
    title = input("Title: ")

    # Prints author of book.
    for book in library:
        if book["title"] == title:
            print(f'Author: {book["author"]}')

main()