# Open and read the file
with open('out_raise.txt', 'r') as file:
    lines = file.readlines()

# Iterate through lines and check for word space 6
for line in lines:
    parts = line.strip().split()
    if len(parts) >= 2:
        word = parts[0]
        try:
            word_space = int(parts[1])
            if word_space == 5:
                print(word)
        except ValueError:
            continue  # If the word space is not an integer, skip
