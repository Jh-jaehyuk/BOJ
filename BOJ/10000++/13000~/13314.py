print("100")
data = [["10000"] * 99 + ["1"] for _ in range(99)]
data.append(["1"] * 100)
for i in range(100):
    data[i][i] = "0"

for i in data:
    print(" ".join(i))