from enum import Enum
from dataclasses import dataclass as component

class FontSizes(Enum):
    EXTRA_SMALL = 8
    SMALL = 10
    MEDIUM = 14
    LARGE = 18
    EXTRA_LARGE = 20

@component
class FontSize():
    value: FontSizes

