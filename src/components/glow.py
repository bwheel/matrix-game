"""
Glow Component Module
"""
from dataclasses import dataclass as component
from enum import Enum


class Glows(Enum):
    """
    Glows enum
    """
    EXTRA_DARK = 0.2
    DARK = 0.8
    NORMAL = 1.0
    BRIGHT = 1.2
    EXTRA_BRIGHT = 1.8


@component
class Glow():
    """
    Glow Component
    """
    glow: Glows
