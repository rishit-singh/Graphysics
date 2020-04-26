import os
import numpy

commands = numpy.array(list([
        "g++ --std=c++17 debug.cpp -o debug;",
        "./debug;"
    ]))


for x in range(len(commands)):
    os.system(commands[x])
