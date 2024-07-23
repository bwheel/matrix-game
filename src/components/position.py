from dataclasses import dataclass as component

@component
class Position():
    x: float
    y: float
    @property
    def spot(self):
        return (self.x, self.y)