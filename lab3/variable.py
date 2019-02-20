#Numeric
width = 20
height = 30
print 'height*width is', height * width

#String manipulation
s = 'First line.\nSecond line.' #\n means newline
print(s) # With print(), \n produces a new line

print('C:\some\name') # here \n means newline!
print(r'C:\some\name') # notice the r before the quote

squares = [1, 4, 9, 16, 25]
print "squarers is", squares

print "squares[0]", squares[0] # indexing return the line
print "squares[-1]", squares[-1] # starts from of the list, so its 25
print "squares[-3:]", squares[-3:] # slicing returns a new list


print "squares + [36, 49, 64, 81, 100]", squares + [36, 49, 64, 81, 100]

cubes = [1, 8, 27, 65, 125]
print "cubes unmodified is", cubes
cubes[3] = 64 # reeplace the wrong value
print "cubes is", cubes

cubes.append(216)
cubes.append(7 ** 3)
print "cubes after append is", cubes

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
print "letters is", letters
# replaces ome values
letters[2:5] = ['C', 'D', 'E']
#replace some values
print "letters modified", letters

#if statements
x = 10
if x < 1:
    print('x is less than 0')
elif x == 0:
    print('x is equal to 0')
elif x == 1:
    print('x is equal to 1')
else:
    print('x is greater than 1')
