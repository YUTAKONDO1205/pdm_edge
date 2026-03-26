# npz2header.py
import numpy as np

data = np.load("norm.npz")
mu = data["mu"]
sigma = data["sigma"]

with open("norm.h", "w") as f:
    f.write("#ifndef NORM_H_\n#define NORM_H_\n\n")
    f.write("#include <stdint.h>\n\n")

    f.write("const int16_t MU[200] = {")
    f.write(",".join(str(int(m)) for m in mu))
    f.write("};\n\n")

    f.write("const int16_t SIG[200] = {")
    f.write(",".join(str(int(s)) if s != 0 else "1" for s in sigma))  # divide-by-zero 対策
    f.write("};\n\n")

    f.write("#endif\n")
