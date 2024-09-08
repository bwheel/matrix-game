"""
Random Number Generator Module
"""
import random
import string
from typing import Tuple

from matrix_game_pygame.components.font_size import FontSizes


def get_random_color() -> Tuple[int, int, int]:
    """
    Get Random Color
    """
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    return (r, g, b)


def get_random_text() -> str:
    """
    Get Random text. Single letter
    """
    idx = random.randint(0, len(string.printable))
    return string.printable[idx - 1]


def get_random_font_size() -> FontSizes:
    """
    Get Random Font Size
    """
    return random.choice(list(FontSizes))


def get_random_speed_from_font_size(font_size: FontSizes) -> float:
    """
    Get Random Speed from Font Size
    """
    match font_size:
        case FontSizes.EXTRA_LARGE:
            return random.randint(10.0, 12.0)
        case FontSizes.LARGE:
            return random.randint(9.0, 10.0)
        case FontSizes.MEDIUM:
            return random.randint(5.0, 8.0)
        case FontSizes.SMALL:
            return random.randint(3.0, 5.0)
        case _:
            return random.randint(1.0, 3.0)
