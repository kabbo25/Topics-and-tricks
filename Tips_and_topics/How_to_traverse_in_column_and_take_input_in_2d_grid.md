```python
g = [[x for x in input()] for i in range(n)] #2d_grid input newa

for row in g:
    print(row) #row traverse kora

for col in zip(*g): # column traverse kora
    print(col)
```