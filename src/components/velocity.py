"""
Velocity Component Module
"""
from dataclasses import dataclass as component


@component
class Velocity():
    """
    Velocity Component
    """
    speed: float
