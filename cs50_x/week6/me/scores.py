# Dynamically gets scores and produces an average score.

def main():
    # Gets input from standard input.
    scores = []
    n = int(input("Number of Scores: "))
    for i in range(n):
        score = int(input(f"Score {i}: "))
        scores.append(score)

    # Prints output to standard output.
    average = sum(scores) / len(scores)
    print(f"Average: {average}")
    
main()