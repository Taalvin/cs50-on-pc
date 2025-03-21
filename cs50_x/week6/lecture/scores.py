# Calculates the average score.

from cs50 import get_int

def main():
    # Gets user input.
    size = pos_get_int("Amount of subjects: ")
    scores = []
    for i in range(size):
        score = pos_get_int(f"score {i + 1}: ")
        scores.append(score)

    # Prints output(i.e Average score).
    print(f"Average score: {sum(scores) / len(scores)}")

# Forces user input to be a positive integer.
def pos_get_int(prompt):
    while True:
        x = get_int(prompt)
        if x > 0:
            return x

main()