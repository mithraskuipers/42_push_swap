import random
tmp = random.sample(range(-5000, 5000), 500)
listToStr = ' '.join(map(str, tmp))
print(listToStr)