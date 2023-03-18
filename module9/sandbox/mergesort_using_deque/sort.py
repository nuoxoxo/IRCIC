import sys, typing, random
from collections import deque

def merge_sort(D):

    # basecase
    if len(D) < 2:
        return

    # split
    size = len(D)
    mid = size // 2
    L = deque()
    R = deque()
    for i in range(mid):
        L.append(D.pop())
    for i in range(size - mid):
        R.append(D.pop())

    # recurse
    merge_sort(L)
    merge_sort(R)

    # compare & insert
    a = [None] * size
    i, j = 0, 0
    while i < len(L) and j < len(R):
        if L[i] > R[j]:
            D.append(R[j])
            j += 1
        else:
            D.append(L[i])
            i += 1

    # get the rest
    while i < len(L):
        D.append(L[i])
        i += 1
    while j < len(R):
        D.append(R[j])
        j += 1


if __name__ == '__main__':
    def debugger(a: list) -> None:
        printlist(a)
        d = deque(a)
        merge_sort(d)
        printlist(list(d), '(sorted)\n')

    def printlist(a: list, end: str = '') -> None:
        if len(a) > 12:
            print(a[:6], '[...]', len(a), end)
        else:
            print(a, len(a), end)

    # DIY test
    if len(sys.argv) == 1:
        a = [2, 11, 1, 42, 21, 64, 6, 3, -42]
        debugger(a)
        a = [2, 11, 1, 42, 21, 64, 6, 3, -42, 21]
        debugger(a)
    # subject test
    else:
        if sys.argv[1] == 'test':
            a = [ int(_) for _ in sys.argv[1:] ]
        print(f"will run with `jot -r 3000 1 100000 | tr '\\n' ' '`")
        a = [ int(_) for _ in sys.argv[1:] ]
        debugger(a)


