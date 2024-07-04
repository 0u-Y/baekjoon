words = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]



word = input()


for i in words:
    word = word.replace(i, '*')




print(len(word))
