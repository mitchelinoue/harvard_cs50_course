# TODO
def main():
    text = get_text()

    num_letters = 0
    for c in range(0, len(text), 1):
        if (text[c].isalpha()):
            num_letters += 1

    num_words = len(text.split())

    num_sentences = 0
    for c in range(0, len(text), 1):
        if (text[c] == '.' or text[c] == '!' or text[c] == '?') and (text[c - 1] != '.' or text[c - 1] != '!' or text[c - 1] != '?'):
            num_sentences += 1

    average_letters = (num_letters / num_words * 100)

    average_sentences = (num_sentences / num_words * 100)

    index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8

    if index < 1:
        print("Before Grade 1")
    elif index < 15:
        print(f"Grade {round(index)}")
    else:
        print("Grade 16+")


def get_text():
    text = input("Text: ")
    return text

main()