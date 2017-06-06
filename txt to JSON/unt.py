import csv
lines = csv.reader(open("airports.txt", "rb"))
mpis = []  # Multidimensional Poverty Index
thousands = []  # People, in thousands, in a poverty situation
deprivations = []  # Intensity of Deprivation
alt=[]

for id, d, mpi, thousand, deprivation,a,lat,lon,alt,e,f,g,h,i in lines:
    mpis += (lat, lon, alt)
    thousands += (lat, lon, alt)
    deprivations += (lat, lon, alt)

print mpis
print """
[
["1990", [%s]],
["1995", [%s]],
["2000", [%s]]
""" % (",".join(mpis),
       ",".join(thousands),
       ",".join(deprivations))