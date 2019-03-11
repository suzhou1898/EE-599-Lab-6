
# EE599-Lab6
# DO NOT CHANGE THE FIRST 10 LINES
# DO NOT INCLUDE ANY OTHER PACKAGE
import random
import os
import time
PARAM = {"seed":26, "size":30,
        "unsortedFile":"input.txt", "sortedFile":"output.txt",
        "range": [0, 100], "alg":"bubbleSort"}

# TASKS:
# Seed your random generator with PARAM["seed"]
# Generate PARAM["size"] integers in range PARAM["range"]
# Write the random integers in PARAM["unsortedFile"]
# Don't forget to close the file (potential bug here!)
# Each integer should be in a separate line
# Compile your C++ code (use "os" package)
# Start a timer
# Run your C++ code with the correct arguments
# Print your timer (in sec) in a single line, that's the only thing you should print
# Write you code below:

j=0
random.seed(PARAM["seed"])
input=open("input.txt","w+")
while(j<PARAM["size"]):
        num=random.randint(PARAM["range"][0],PARAM["range"][1])
        input.write(str(num)+"\n")
        j=j+1
input.close()
os.system("g++ -std=c++11 -c main.cpp")
os.system("g++ -std=c++11 -c sort.cpp")
os.system("g++ main.o sort.o -o SortMethods.out")
start=time.time()
os.system("./SortMethods.out %s %s %s %s" % (PARAM["unsortedFile"],PARAM["sortedFile"],PARAM["size"],PARAM["alg"]))
end=time.time()
print(end-start)


