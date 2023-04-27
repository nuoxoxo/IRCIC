def solve(s):
    diffU = ord('Z') + ord('A')
    diffL = ord('z') + ord('a')
    return ''.join([ \
            _ if not _.isalnum() else \
            (chr(diffL - ord(_)) if _.islower() else chr(diffU - ord(_))) \
            for _ in s ])

s = input('text: ')
print(solve(s))
