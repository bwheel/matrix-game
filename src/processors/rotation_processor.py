"""
Rotation Processor Module
"""
import esper
import pygame

from components.character import Character
from components.rotatable import Rotatable
from domain import rng


class RotationProcessor(esper.Processor):
    """
    Rotation Processor
    """

    def process(self, *_, **__):
        for _, (r, c) in esper.get_components(Rotatable, Character):
            ticks = pygame.time.get_ticks()
            if ticks - r.last_rotation_ms > r.rotate_interval:
                c.value = rng.get_random_text()
                r.last_rotation_ms = ticks
