class Dog:
    kind = 'canine'
    
    def __init__(self, name):
        self.name = name # instance variable unique to each instance

d = Dog('Fido')
e = Dog('Buddy')
print "d.kind is", d.kind, "d.name is", d.name
print "e.kind is", e.kind, "e.name is", e.name
