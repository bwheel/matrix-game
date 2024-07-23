from typing import Tuple
from dataclasses import dataclass as component

import pygame


@component
class Display():
    screen: pygame.Surface
    size: Tuple[int, int]
    background_color: Tuple[int, int, int]
    color: Tuple[int, int, int]