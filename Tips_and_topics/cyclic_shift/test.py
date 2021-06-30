from collections import deque

d = deque([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
d.rotate(3)  # to the right
print(*d)
d.rotate(-3)  # back to the left
