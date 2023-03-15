def calc(line):
    a = line.split()
    dq = []
    for c in a:
        if c in '+-*/':
            r = 0 if len(dq) == 0 else dq.pop()
            l = 0 if len(dq) == 0 else dq.pop()
            if c == '+':
                dq.append(l + r)
            elif c == '-':
                dq.append(l - r)
            elif c == '*':
                dq.append(l * r)
            elif c == '/':
                dq.append(round(l / r))
        elif not c.isnumeric():
            if c[0] in '+-' and c[1:].isnumeric:
                dq.append(int(c))
            else:
                return 'Error'
        elif c.isnumeric():
            dq.append(int(c))
    return dq.pop()

def test(expr, res):
    print("expression: {} \nresult: {} \n".format(expr, calc(expr)))
    assert(res == calc(expr))

test('8 9 * 9 - 9 - 9 - 4 - 1 +', 42)
test('7 7 * 7 -', 42)
test('(1 + 1)', 'Error')
test('10 6 9 3 + -11 * / * 17 + 5 +', 22)




"""
expr = '8 9 * 9 - 9 - 9 - 4 - 1 +'
print("expression: {} \nresult: {} \n".format(expr, calc(expr)))
assert(calc(expr) == 42)

expr = '7 7 * 7 -'
print("expression: {} \nresult: {} \n".format(expr, calc(expr)))
assert(calc(expr) == 42)

expr = '10 6 9 3 + -11 * / * 17 + 5 +'
print("expression: {} \nresult: {} \n".format(expr, calc(expr)))
assert(calc(expr) == 22)

expr = '(1 + 1)'
print("expression: {} \nresult: {} \n".format(expr, calc(expr)))
assert(calc(expr) == 'Error')
"""

