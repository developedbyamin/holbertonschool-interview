# 0x19-making_change
This interview algorithm project uses a given pile of coins of different values and evaluates the fewest number of coins needed to meet a given amount total.

[Change Comes from Within](/0x19-making_change/0-making_change.py)
* Write a function in Python `def makeChange(coins, total)` that calculates the fewest number of coins needed to meet a given amount total with a given pile of different-valued coins:
  * `coins` is a list of the values of the coins in your possession
  * each coin has a value of an integer greater than 0
  * it can be assumed you have an infinite number of each coin in the list
  * if the `total` is 0 or less, return 0
  * if the `total` cannot be met by any number of coins you have, return -1
  * else, return the fewest number of coins needed to meet the `total`

### test_files
The test_files/ directory contains files used to test the output of the algorithm locally.