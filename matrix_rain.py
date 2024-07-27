import sys
import random
from typing import List, Tuple, Dict, Optional
from dataclasses import dataclass as component

import esper
import pygame

from src.components import Position, Velocity, Character, Display, FontSize, FontSizes, Fonts, Glow, Glows, Rotatable
from src.processors import RenderProcessor, MovementProcessor
from src.domain import rng
from src.domain import gfx
from src.processors.rotation_processor import RotationProcessor

def seed_display(screen: pygame.Surface, screen_size: Tuple[int, int], background_color: Tuple[int, int, int], font_color: Tuple[int, int, int]):
        display = esper.create_entity()
        esper.add_component(display, Display(
            screen=screen,
            size=screen_size,
            background_color=background_color,
            color=font_color,
            ))

def seed_fonts():
    fonts_entity = esper.create_entity()
    default_font = pygame.font.get_default_font()
    esper.add_component(fonts_entity, Fonts(
        extra_small=pygame.font.Font(default_font, FontSizes.EXTRA_SMALL.value),
        small=pygame.font.Font(default_font, FontSizes.SMALL.value),
        medium=pygame.font.Font(default_font, FontSizes.MEDIUM.value),
        large=pygame.font.Font(default_font, FontSizes.LARGE.value),
        extra_large=pygame.font.Font(default_font, FontSizes.EXTRA_LARGE.value),
    ))

def seed_rain(cols: int, letter_width: float, screen_height: int):
    for col in range(cols):
        seed_cascade(float(col ) * letter_width, screen_height )

def seed_cascade(col: float, screen_height: int):
    font_size = random.choice(list(FontSizes))
    match font_size:
        case FontSizes.EXTRA_LARGE:
            speed = random.randint(10,15)
        case FontSizes.LARGE:
            speed = random.randint(10,12)
        case FontSizes.MEDIUM:
            speed = random.randint(5,9)
        case FontSizes.SMALL:
            speed = random.randint(3,5)
        case _:
            speed = random.randint(1,3)
            
    letter_height = gfx.get_letter_height(font_size)
    start_row = random.randint(0, screen_height)
    max_row_count = int((screen_height / 3.0) / letter_height)
    rows = random.randint(0, max_row_count)
    

    rotation_interval = None

    for idx, row in enumerate(range(rows)):
        glow = Glows.NORMAL
        # bottom
        if idx + 1 == rows:
            glow = Glows.BRIGHT
            flip = random.uniform(0, 1)
            if flip > .8:
                glow = Glows.EXTRA_BRIGHT
                rotation_interval = random.choice([10, 50, 150, 250, 500, 800, 1000, 1500])
        # top
        elif idx == 0:
            glow = Glows.EXTRA_DARK
        else:
            flip = random.uniform(0, 1)
            if flip > .99:
                glow = Glows.EXTRA_BRIGHT
                rotation_interval = random.choice([250, 500, 800, 1000, 1500])

        

        y = start_row + row * letter_height
        if y >= screen_height:
            y = y - screen_height
        seed_letter(
            x=col,
            y=float(y),
            speed=speed,
            font_size=font_size,
            glow=glow,
            rotation_interval=rotation_interval
        )

def seed_letter(x: float, y: float, speed: float, font_size: FontSizes, glow: Glows, rotation_interval: Optional[float]):
    entity = esper.create_entity()
    txt = rng.get_random_text()
    esper.add_component(entity, Position(
        x=x,
        y=y
    ))
    esper.add_component(entity, Velocity(
        speed=speed
    ))
    esper.add_component(entity, Character(
        value=txt,
    ))
    esper.add_component(entity, FontSize(
        value=font_size
    ))
    esper.add_component(entity, Glow(
        glow=glow
    ))
    if rotation_interval is not None:
        ticks = pygame.time.get_ticks()
        esper.add_component(entity, Rotatable(
            rotate_interval=rotation_interval,
            last_rotation_ms=ticks,
        ))
    print(f'entity:{entity}, position:(x={x},y={y}) speed:{speed}, txt:{txt}')



def main():
    try:
        # setup display engine
        pygame.init()
        clock = pygame.time.Clock()
        screen_size = gfx.get_screen_size()
        screen = gfx.create_screen(screen_size)
        background_color = (0, 0, 0)
        font_color = rng.get_random_color()
        letter_width = gfx.get_letter_width(FontSizes.MEDIUM)
        # add entities with components
        seed_fonts()
        seed_display(
            screen=screen,
            screen_size=screen_size,
            background_color=background_color,
            font_color=font_color)
        cols =  int(screen_size[0] / letter_width)
        seed_rain(cols, letter_width, screen_size[1])
        
        esper.add_processor(MovementProcessor())
        esper.add_processor(RenderProcessor())
        esper.add_processor(RotationProcessor())


        keep_running = True
        while keep_running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    keep_running = False
                    break
                elif event.type == pygame.KEYDOWN:
                    match event.key:
                        case pygame.K_ESCAPE:
                            keep_running = False
                        case pygame.K_SPACE:
                            _, display = esper.get_component(Display)[0]
                            display.color = rng.get_random_color()
                        case pygame.K_UP:
                            for _, (v) in esper.get_component(Velocity):
                                #v.speed /= 2
                                speed = v.speed - 1
                                if speed >= 0:
                                    v.speed = speed
                        case pygame.K_DOWN:
                            for _, (v) in esper.get_component(Velocity):
                                #v.speed *= 2
                                speed = v.speed + 1
                                if speed <= 100:
                                    v.speed = speed
                        case _:
                            pass
                                    

            
            # run systems
            esper.process()
            
            # apply rendering
            pygame.display.update()
            clock.tick(60)
        
    except Exception as ex:
        print(str(ex))
        sys.exit(1)


if __name__ == "__main__":
    main()