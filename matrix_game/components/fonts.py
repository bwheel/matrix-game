"""
Fonts Component Module
"""
from dataclasses import dataclass as component

import pygame


@component
class Fonts():
    """
    Fonts Component
    """
    extra_small: pygame.font.Font
    small: pygame.font.Font
    medium: pygame.font.Font
    large: pygame.font.Font
    extra_large: pygame.font.Font
