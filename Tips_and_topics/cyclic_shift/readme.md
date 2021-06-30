# Left cyclic shift- if we left shift k times that means , first k elements go to last and (n-k) elements come first

```python
d = deque([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
# d.rotate(3)  # to the right

d.rotate(-3)  # back to the left
print(d) #deque([3, 4, 5, 6, 7, 8, 9, 0, 1, 2])
```

# Here we can see that after shifting 3 times left first 3 elements go last and (n-3)elements come first

# right shift is just opposite,last k elements comes first,(n-k) elements shift by right k times

```python
d = deque([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 d.rotate(3)  # to the right

#d.rotate(-3)  # back to the left
print(d) # 7 8 9 0 1 2 3 4 5 6
```

# what is the cost of cyclic shift

---

# here cost of the cyclic shift is that if the position at i element is not equal i then cost will be how many elements are not equal or `a[i]!=i`

```python
a=[1,2,3,4,5]
b=[3,5,4,2,1]

# Here total cost is 5
```

## first question is:

---

> we have given an permutation and Q query and we have to tell in every query what is the cost after performing kth cyclic shift

## for a n length permutation there is only n unique permutation ,so that

> permutation after kth shift is=`(k%n)`th shift

## An element is only it's right position only in 1 cyclic shift of N cyclic shift, because every element is unique once it gets disposition ,it will remain at wrong place

# In the cyclic shift , if k element is on the right position then cost will be =`N-k` , so we just have to increase the K to minimize the cost

## To calculate the value of K, we just need an frquency array

```python
# a [2 4 3 1 5]
# b [1 2 0 2 1] here b[i] represents number of right shift need to place that elements at right position

# maximum frequency of list b will our K because after that amount right shift ,maximum element will be at his right position

# to calculate the b[i] or how many right shifts actually need for each element can be done by this formula,

for jth element,(j-pos[j]+N)%N
```

## left rotation and right rotation are same , so if we check right rotation we don't' have to check another rotation
