import esper

from ..components import Display, Position, Velocity

class MovementProcessor(esper.Processor):

    def process(self):
        _, display = esper.get_component(Display)[0]
        for entity, (vel, pos) in esper.get_components(Velocity, Position):
            next_y =  pos.y + vel.speed
            if next_y > display.size[1]:
                next_y = 0 
            pos.y = next_y
