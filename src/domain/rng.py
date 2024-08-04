
import random
import string
from typing import Tuple, List

from ..components import FontSizes


def get_random_color() -> Tuple[int, int, int]:
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    return (r, g, b)

def get_random_text() -> str:
    idx = random.randint(0, len(string.printable))
    return string.printable[idx - 1]

def get_random_font_size() -> FontSizes:
    return random.choice(list(FontSizes))

def get_random_speed_from_font_size(font_size: FontSizes) -> float:
    speed = 1.0
    match font_size:
        case FontSizes.EXTRA_LARGE:
            speed = random.randint(10,15)
        case FontSizes.LARGE:
            speed = random.randint(10,12)
        case FontSizes.MEDIUM:
            speed = random.randint(5,9)
        case FontSizes.SMALL:
            speed = random.randint(3,5)
        case _:
            speed = random.randint(1,3)
    return float(speed)