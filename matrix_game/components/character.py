"""
Character Component Module
"""
from dataclasses import dataclass as component


@component
class Character():
    """
    Character Component
    """
    value: str
