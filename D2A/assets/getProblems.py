#!/usr/bin/env python3

import os
from sys import argv
from urllib.request import urlopen
from pyquery import PyQuery as pq

# present working directory
# contest id -- problem number

pwd = argv[1]
problem = argv[2]

if not os.path.exists(f"{problem}"):
    os.makedirs(f"{problem}")
    os.makedirs(f"{problem}/samples")

sampleTestData = []
problemUrl = f"https://codeforces.com/contest/{problem}/problem/A"
problemHtml = urlopen(url=problemUrl)
pqParser = pq(url=problemUrl,
        opener = lambda url, **kw: urlopen(url).read())

tests = pqParser('.sample-test')
inputs = tests.find('.input')
inputs = inputs.find('pre')
inputVals = []
inputs.each(lambda i,this: inputVals.append(pq(this).text()))

outputs = tests.find('.output')
outputs = outputs.find('pre')
outputVals = []
outputs.each(lambda i,this: outputVals.append(pq(this).text()))

inputFile = open(f"{problem}/samples/data.in", "w")
outputFile = open(f"{problem}/samples/data.out", "w")

inputFileStr = f"{len(inputs)}\n"
for val in inputVals:
    inputFileStr+=val
    inputFileStr+='\n'

outputFileStr = ""
for val in outputVals:
    outputFileStr+=val
    outputFileStr+='\n'

# removing trailing new line char
inputFileStr = inputFileStr[:-1]
outputFileStr = outputFileStr[:-1]

inputFile.write(inputFileStr)
outputFile.write(outputFileStr)
