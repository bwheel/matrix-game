from enum import Enum
from dataclasses import dataclass as component

class FontSizes(Enum):
    EXTRA_SMALL = 12
    SMALL = 18
    MEDIUM = 24
    LARGE = 36
    EXTRA_LARGE = 42

@component
class FontSize():
    value: FontSizes

