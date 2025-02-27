import sys
import math

c = math.sin(math.radians(108)) / math.sin(math.radians(63))

for line in sys.stdin:
    s = float(line)
    print(f"{s * c:.10f}")
