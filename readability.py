text = input("Text: ")

letters, words, sentences = 0, 1, 0

for c in text:
    if c.isalpha():
        letters += 1
    elif c == " ":
        words += 1
    elif c in [".", "!", "?"]:
        sentences += 1

coef = 100 / words 
l = coef * letters
s = coef * sentences

index = 0.0588 * l - 0.296 * s - 15.8
print(f"coef={coef}, l={l}, s={s}, index={index}")

if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")
