words = ['cat', 'window', 'defenestrate']

for w in words:
    print(w, len(w))

for n in range(2,10):
    print('n is', n)

#continue to continue with next iteration

for num in range(2,10):
    if num % 2 == 0:
        print("Found an even number", num)
        continue #continue breaks the current iteration and goes to the next iteration in the loop
    print("Found a number", num)

