from pathlib import Path
from typing import Tuple, Optional, Union
import colorsys

import pygame

from ..components import Fonts, FontSizes

def get_font_file():
    # {
    #     "assets/FiraCode.ttf" : Path("assets/FiraCode.ttf").exists(),
    #     "assets/FromCartoonBlocks.ttf" : Path("assets/FiraCode.ttf").exists()
    # }
    
    font_file = "assets/FromCartoonBlocks.ttf" if Path("assets/FromCartoonBlocks.ttf").exists() else pygame.font.get_default_font()
    return font_file

def create_screen(screen_size: Tuple[int, int]) -> pygame.Surface:
    win_style = pygame.DOUBLEBUF #| pygame.FULLSCREEN
    best_depth = pygame.display.mode_ok(screen_size, win_style, 32)
    screen = pygame.display.set_mode(screen_size, win_style, best_depth)
    return screen

def get_screen_size() -> Tuple[int, int]:
    display_info = pygame.display.Info()
    screen_size = display_info.current_w, display_info.current_h
    return screen_size

def get_font_size(font: Union[pygame.font.Font, FontSizes]) -> Tuple[int, int]:
    if isinstance(font, FontSizes):
        font = pygame.font.Font(get_font_file(), font.value)
    font_surface = font.render("_", False, (0,0,0))
    return (font_surface.get_width(), font_surface.get_height())

def get_letter_height(font: Union[pygame.font.Font, FontSizes]) -> int:
    if isinstance(font, FontSizes):
        font = pygame.font.Font(get_font_file(), font.value)
    font_surface = font.render("_", False, (0,0,0))
    return font_surface.get_height()

def get_letter_width(font: Union[pygame.font.Font, FontSizes]) -> int:
    if isinstance(font, FontSizes):
        font = pygame.font.Font(get_font_file(), font.value)
    font_surface = font.render("_", False, (0,0,0))
    return font_surface.get_width()

def get_font_from_size(fonts: Fonts, font_size: FontSizes) -> Optional[pygame.font.Font]:
    match font_size.value:
        case FontSizes.EXTRA_SMALL:
            return fonts.extra_small
        case FontSizes.SMALL:
            return fonts.small
        case FontSizes.MEDIUM:
            return fonts.medium
        case FontSizes.LARGE:
            return fonts.large
        case FontSizes.EXTRA_LARGE:
            return fonts.extra_large
        case _:
            return None


def adjust_color_lightness(color: Tuple[int, int, int], factor: float) -> Tuple[int, int, int]:
        r, g, b = color
        h, l, s = colorsys.rgb_to_hls(r / 255.0, g / 255.0, b / 255.0)
        l = max(min(l * factor, 1.0), 0.0)
        r, g, b = colorsys.hls_to_rgb(h, l, s)
        return int(r * 255), int(g * 255), int(b * 255)