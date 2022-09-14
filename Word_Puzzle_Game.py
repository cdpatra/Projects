import random
print(" Word Puzzle Game ".center(100, '#'))
print()
print("5 scrambled words will be given one by one.")
print("You have to unscramble them")
print("If your answer is correct your then score will increase by 1")
print("If your answer is wrong then your score will decrease by 1")
print("BEST OF LUCK")
print()
print()
words = [('ragend', 'garden'), ('willpo', 'pillow'), ('pomcetru', 'computer'), ('hawle', 'whale'),
         ('iudsq', 'squid'), ('hskra', 'shark'), ('eociv', 'voice'), ('anrel', 'learn'), ('oocdrt', 'doctor'), ('eonrufldw', 'wonderful'), ('nsmgmiiw', 'swimming'), ('cpelin', 'pencil')]
while True:
    score = 0
    random_index_list = []
    while len(random_index_list) != 10:
        rand_var = random.randint(0, 9)
        if random_index_list.count(rand_var*7 % 10) == 0:
            random_index_list.append(rand_var*7 % 10)
    for e in range(5):
        print("Arrange the letters to form a valid word:")
        print((words[random_index_list[e]][0]).upper())
        if words[random_index_list[e]][1] == (input()).lower():
            print('Correct\n')
            score += 1
        else:
            print('Wrong\n')
            score -= 1
    print("Net score is :", score)
    if input("Want to play again [y/n]: ") == 'y':
        pass
    else:
        break
