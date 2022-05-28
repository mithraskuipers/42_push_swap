import random
tmp = random.sample(range(0,500), 500)
listToStr = ' '.join(map(str, tmp))
print(listToStr)