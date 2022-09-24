import pandas as pd
import matplotlib.pyplot as plt


fname = "pt2.txt"
df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)

print("var names =", var_names)

# split the df into individual vars
# assumption: there are 3 columns of numbers in the input file

problem_sizes = df[var_names[0]].values.tolist()

blas = df[var_names[1]].values.tolist()
b2 = df[var_names[2]].values.tolist()
b16 = df[var_names[3]].values.tolist()
b32 = df[var_names[4]].values.tolist()
b64 = df[var_names[5]].values.tolist()



plt.title("BLAS vs Blocked MM")

xlocs = [i for i in range(len(problem_sizes))]

#Scientific Notation for X-axis
plt.xticks(xlocs, ['{:.3e}'.format(x) for x in problem_sizes])

plt.plot(blas, "r-+")
plt.plot(b2, "b-x")
plt.plot(b16, "g-x")
plt.plot(b32, "c-x")
plt.plot(b64, "y-x")

#plt.xscale("log")
plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("MegaFlops Per Second")

varNames = [var_names[1], var_names[2], var_names[3], var_names[4], var_names[5]]
plt.legend(varNames, loc="best")

plt.grid(axis='both')

plt.show()

# EOF
