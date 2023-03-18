import sys, typing
from collections import deque
from random import randint

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

    a = []

    # pmergeme test
    if len(sys.argv) == 1:
        a = [3, 5, 9, 7, 4]
        debugger(a)
        a = [2, 11, 1, 42, 21, 64, 6, 3, -42]
        debugger(a)
        a = [2, 11, 1, 42, 21, 64, 6, 3, -42, 21]
        debugger(a)
    # random test
    else:
        print(sys.argv[1])
        if sys.argv[1] == 'test':
            a = [ randint(1, 100000) for _ in range(0, 3000) ]
        else:
            a = [ int(_) for _ in sys.argv[1:] ]
    debugger(a)

