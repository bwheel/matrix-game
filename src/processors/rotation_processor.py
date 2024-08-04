
import esper
import pygame

from ..components import Rotatable, Character

from ..domain import rng

class RotationProcessor(esper.Processor):

    def process(self):
        for _, (r, c) in esper.get_components( Rotatable, Character):
            ticks = pygame.time.get_ticks()
            if ticks - r.last_rotation_ms > r.rotate_interval:
                c.value = rng.get_random_text()
                r.last_rotation_ms = ticks

