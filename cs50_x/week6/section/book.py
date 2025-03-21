# Simple program showcasing dictionary.

def main():
    # Creating a dictionary called book.
    book = dict()

    # NOTE: "title" is the key and "Reverend Insanity" is the value
    #       associated with it.
    book["title"] = "Reverend Insanity"

    # NOTE: "author" is the key and "Gu Zhen Ren" is the value
    #       associated with it.   
    book["author"] = "Gu Zhen Ren"

    # Accessing the value associated with its key.
    print(f'Title: {book["title"]}')
    print(f'Author: {book["author"]}') 

main()