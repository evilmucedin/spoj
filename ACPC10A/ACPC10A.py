import sys

for line in sys.stdin:
	parts = line.split()
	a1 = int(parts[0])
	a2 = int(parts[1])
	a3 = int(parts[2])
	if a1 == 0 and a2 == 0 and a3 == 0:
		break;
	if a3 + a1 == a2 - a2:
		print("AP %d" % (a3 + a3 - a2))
	else:
		print("GP %d" % (a3*a3/a2))