# Simple program showcasing tuples.

# Creating a list of tuples.
DOB = [
    ("Nemisha", 2004),
    ("Taalvin", 2004),
    ("Sekha", 1999),
    ("Yuvisha", 2007)
]

# NOTE: Order matters - Person came in front of year.
for person, year in DOB:
    print(f"{person} was born in the year, {year}.")