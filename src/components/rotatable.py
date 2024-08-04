
from dataclasses import dataclass as component

@component
class Rotatable():
    rotate_interval: int
    last_rotation_ms: int

