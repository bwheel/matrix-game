from dataclasses import dataclass as component
from enum import Enum

class Glows(Enum):
    EXTRA_DARK = 0.2
    DARK = 0.8
    NORMAL = 1.0
    BRIGHT = 1.2
    EXTRA_BRIGHT = 1.8

@component
class Glow():
    glow: Glows