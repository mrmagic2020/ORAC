# PASSED

inputFile = open("addin.txt", "r")
outputFile = open("addout.txt", "w")

a, b = [int(x) for x in list((inputFile.read().split(" ")))]

outputFile.write(str(a + b))

inputFile.close()
outputFile.close()
