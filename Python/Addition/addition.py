# PASSED
#
# Starter Problems
# @link https://orac2.info/problem/simpleadd/
# @author mrmagic2020

inputFile = open("addin.txt", "r")
outputFile = open("addout.txt", "w")

a, b = [int(x) for x in list((inputFile.read().split(" ")))]

outputFile.write(str(a + b))

inputFile.close()
outputFile.close()
