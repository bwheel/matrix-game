"""
Seeding Data Module
"""
import random
from typing import Tuple, Optional

import pygame
import esper

from matrix_game.components.character import Character
from matrix_game.components.display import Display
from matrix_game.components.font_size import FontSize, FontSizes
from matrix_game.components.fonts import Fonts
from matrix_game.components.glow import Glow, Glows
from matrix_game.components.position import Position
from matrix_game.components.rotatable import Rotatable
from matrix_game.components.velocity import Velocity

import matrix_game.domain.gfx as gfx
import matrix_game.domain.rng as rng


def seed_display(
        screen: pygame.Surface,
        screen_size: Tuple[int, int],
        background_color: Tuple[int, int, int],
        font_color: Tuple[int, int, int]
):
    """
    Seed Display
    """
    display = esper.create_entity()
    esper.add_component(display, Display(
        screen=screen,
        size=screen_size,
        background_color=background_color,
        color=font_color,
    ))


def seed_fonts():
    """
    Seed Fonts
    """
    fonts_entity = esper.create_entity()

    esper.add_component(fonts_entity, Fonts(
        extra_small=pygame.font.Font(
            gfx.get_font_file(), FontSizes.EXTRA_SMALL.value),
        small=pygame.font.Font(gfx.get_font_file(), FontSizes.SMALL.value),
        medium=pygame.font.Font(gfx.get_font_file(), FontSizes.MEDIUM.value),
        large=pygame.font.Font(gfx.get_font_file(), FontSizes.LARGE.value),
        extra_large=pygame.font.Font(
            gfx.get_font_file(), FontSizes.EXTRA_LARGE.value),
    ))


def seed_rain(cols: int, letter_width: float, screen_height: int):
    """
    Seed Rain
    """
    for col in range(cols):
        seed_cascade(float(col) * letter_width, screen_height)


def seed_cascade(col: float, screen_height: int):
    """
    Seed Cascade - column of letters
    """
    font_size = rng.get_random_font_size()
    speed = rng.get_random_speed_from_font_size(font_size)

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
                rotation_interval = random.choice(
                    [10, 50, 150, 250, 500, 800, 1000, 1500])
        # top
        elif idx == 0:
            glow = Glows.EXTRA_DARK
        else:
            flip = random.uniform(0, 1)
            if flip > .99:
                glow = Glows.EXTRA_BRIGHT
                rotation_interval = random.choice([250, 500, 800, 1000])

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


def seed_letter(
        x: float,
        y: float,
        speed: float,
        font_size: FontSizes,
        glow: Glows,
        rotation_interval: Optional[float]
):
    """
    Seed single letter
    """
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
