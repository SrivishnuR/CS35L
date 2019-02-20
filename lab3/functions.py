def printDetails( name, age = "16"):
    print ("Name: ", name)
    print ("Age : ", age)
    return;

print ("Using default value")
printDetails(name="Sucharitha")
print("***************************")
print("Overwriting default value")
printDetails(name="Sucharitha", age = "21")
