from collections import deque

def merge_sort(D):
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

    # odd length
    a = [2, 11, 1, 42, 21, 64, 6, 3, 21]
    d = deque(a)
    print(a, len(a))
    merge_sort(d)
    print("(sorted) ", list(d), end='\n\n')

    # even length
    a = [2, 11, 1, 42, 21, 64, 6, 3, 21, -43]
    d = deque(a)
    print(a, len(a))
    merge_sort(d)
    print("(sorted) ", list(d))

