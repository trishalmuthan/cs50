from cs50 import get_string, get_int, get_float


def main():

    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    averageLetters = avgLetters(letters, words)
    averageSentences = avgSentences(sentences, words)


    coleman = calcColeman(averageLetters, averageSentences)
    rounded = round(coleman)

    if rounded < 1:
        print("Before Grade 1")
    elif rounded >= 16:
        print("Grade 16+")
    else:
        print("Grade " + str(rounded))

def count_letters(text):
    count = 0
    for c in text:
        if c.isalpha():
            count += 1
    return count


def count_words(text):
    count = 0
    for c in text:
        if c.isspace():
            count += 1
    return count + 1


def count_sentences(text):
    count = 0
    for c in text:
        if c == '.' or c == '!' or c == '?':
            count += 1
    return count


def avgLetters(letters, words):
    return (letters / words) * 100


def avgSentences(sentences, words):
    return (sentences / words) * 100


def calcColeman(avgLetters, avgSentences):
    return 0.0588 * avgLetters - 0.296 * avgSentences - 15.8

main()
