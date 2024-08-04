"""
Movement Processor Module
"""
import esper

from components.display import Display
from components.position import Position
from components.velocity import Velocity


class MovementProcessor(esper.Processor):
    """
    Movement Processor
    """

    def process(self, *_, **__):
        _, display = esper.get_component(Display)[0]
        for _, (vel, pos) in esper.get_components(Velocity, Position):
            next_y = pos.y + vel.speed
            if next_y > display.size[1]:
                next_y = 0
            pos.y = next_y
