bool isPrime(int x) {
if (x < 2) return false;
for (int y = 2; y \* y <= x; y++)
if (x % y == 0)
return false;
return true;
}
