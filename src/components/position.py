"""
Position Component Module
"""
from dataclasses import dataclass as component
from typing import Tuple


@component
class Position():
    """
    Position Component
    """
    x: float
    y: float

    @property
    def spot(self) -> Tuple[int, int]:
        """
        Returns as a tuple
        """
        return (self.x, self.y)
