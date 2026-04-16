#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
import sys

if len(sys.argv) < 2:
    print(f"usage: {sys.argv[0]} <file>")
    exit(1)

plt.rc("font", family="serif", size=30)
plt.rc("text", usetex=True)
plt.rc("text.latex", preamble=r"""
       \usepackage[utf8]{inputenc}
       \usepackage[russian]{babel}
       \usepackage{amsmath}""")

index, count = np.loadtxt(sys.argv[1], delimiter=",", comments="#", unpack=True)
plt.bar(index, count)
plt.show()
