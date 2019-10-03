from algorithms import selection_sort
import random

l = list(map(lambda x: random.randint(10,99), range(12)))

print(l)
selection_sort(l)
print(l)

words = ['y', 'n', 'hello', 'goodbye', 'please', 'thanks']
selection_sort(words)
print(words)