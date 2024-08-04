"""
Font Sizes Component Module
"""
from enum import Enum
from dataclasses import dataclass as component


class FontSizes(Enum):
    """
    Font Sizes Enum
    """
    EXTRA_SMALL = 12
    SMALL = 18
    MEDIUM = 24
    LARGE = 36
    EXTRA_LARGE = 42


@component
class FontSize():
    """
    Font Sizes Component
    """
    value: FontSizes
