from math import ceil

def printer(x) -> None:
    print(x, '\tceil: ', ceil(x))


a = 0.1
printer(a)

b = 0.4
printer(b)

c = 0.5
printer(c)

d = 0.6
printer(d)

e = 0.9
printer(e)

f = 42.42
printer(f)

g = 99.3
printer(g)

h = 99.9
printer(h)
