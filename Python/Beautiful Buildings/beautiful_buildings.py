# PASSED
#
# AIO 2022
# @link https://orac2.info/problem/aio22buildings/
# @author mrmagic2020

inputFile = open("buildin.txt", "r")
outputFile = open("buildout.txt", "w")

n = int(inputFile.readline().strip())

heightList = [int(x) for x in list(inputFile.readline().strip().split())]

# uglinessSum = sum of ugliness of all buildings
# maxDiff = the maximum reduction in ugliness a single building can achieve
# maxDiffIndex = the index of the building that can achieve the maximum reduction in ugliness
# newHeight = the new height of the building that can achieve the maximum reduction in ugliness
uglinessSum = maxDiff = maxDiffIndex = newHeight = 0

# Loop through each building
for i in range(n):
    height = heightList[i]  # Current building height

    height_next = (
        heightList[i + 1] if i != n - 1 else 0
    )  # Next building height, if it exists

    height_prev = (
        heightList[i - 1] if i != 0 else 0
    )  # Previous building height, if it exists

    uglinessSum += (
        abs(height_next - height) if i != n - 1 else 0
    )  # Add ugliness of next building, if it exists

    if i == 0:  # First building
        maxDiff = abs(height_next - height)
        maxDiffIndex = i
        newHeight = height_next
    elif i == (n - 1):  # Last building
        diff = abs(height - height_prev)
        if diff > maxDiff:
            maxDiff = diff
            maxDiffIndex = i
            newHeight = height_prev
    else:  # Other buildings
        ugliness_old = abs(height - height_prev) + abs(height_next - height)
        height_new = (height_prev + height_next) / 2
        ugliness_new = abs(height_new - height_prev) + abs(height_next - height_new)
        diff = abs(ugliness_old - ugliness_new)
        if diff > maxDiff:
            maxDiff = diff
            maxDiffIndex = i
            newHeight = height_new

if maxDiffIndex != 0:
    uglinessSum -= abs(heightList[maxDiffIndex] - heightList[maxDiffIndex - 1])
    uglinessSum += abs(newHeight - heightList[maxDiffIndex - 1])

if maxDiffIndex != (n - 1):
    uglinessSum -= abs(heightList[maxDiffIndex + 1] - heightList[maxDiffIndex])
    uglinessSum += abs(heightList[maxDiffIndex + 1] - newHeight)

outputFile.write(str(int(uglinessSum)))
outputFile.close()
inputFile.close()
