| n | bin(n) |f(0, n) |
| :--: | :--: | :--: |
| 1 | 0001 | 0001 |
| 2 | 0010 | 0011 |
| 3 | 0011 | 0000 |
| 4 | 0100 | 0100 |
| 5 | 0101 | 0001 |
| 6 | 0110 | 0111 |
| 7 | 0111 | 0000 |
| 8 | 1000 | 1000 |
| 9 | 1001 | 0001 |

$n = 1$ から4個ずつ、それぞれ $f(0, n)$ が $1,\ n + 1,\ 0,\ n$ になっているから累積Xorを $O(1)$ で求められる。
あとは $f(A,B) = f(0, B) \oplus f(0, A - 1)$