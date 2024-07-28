
import random
import string
from typing import Tuple


def get_random_color() -> Tuple[int, int, int]:
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    return (r, g, b)

def get_random_text() -> str:
    idx = random.randint(0, len(string.printable))
    return string.printable[idx - 1]
