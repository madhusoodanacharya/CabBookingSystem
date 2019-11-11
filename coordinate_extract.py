coordinates = []
with open("data.csv", mode = "r", encoding = "utf-8") as f:
    lines = f.readlines()
for i in lines:
    temp = i.split(",")
    coordinates.append((temp[0], temp[1], temp[3][1::]))
# with open("final.txt", mode = "w", encoding = "utf-8") as f:
#     for i in coordinates:
#         f.write(i[1]+","+i[0]+","+i[2]+"\n")


l = {float(i[1]) for i in coordinates}
print(min(l))
print(max(l))

