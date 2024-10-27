"""
Rotation Component Module
"""
from dataclasses import dataclass as component


@component
class Rotatable():
    """
    Rotation Component
    """
    rotate_interval: int
    last_rotation_ms: int
