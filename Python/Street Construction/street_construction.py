# PASSED
#
# Starter Set I: AIO Problems
# @link https://orac2.info/problem/aio18street/

from math import ceil


inputFile = open("streetin.txt", "r")
outputFile = open("streetout.txt", "w")

n, k = [int(x) for x in list((inputFile.read().split(" ")))]

ans = ceil((n - k) / (k + 1))

outputFile.write(str(ans))
