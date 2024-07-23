from typing import Optional, Tuple

import esper
import pygame

from ..components import Display, Position, Character, FontSize, FontSizes, Fonts, Glow, Glows
from ..domain import gfx



class RenderProcessor(esper.Processor):

    def process(self):
        _, display = esper.get_component(Display)[0]
        display.screen.fill(display.background_color)
        _, fonts = esper.get_component(Fonts)[0]
        for _, (pos, character, font_size, g) in esper.get_components(Position, Character, FontSize, Glow):
            font = gfx.get_font_from_size(fonts, font_size)
            if font is None:
                continue
            color = gfx.adjust_color_lightness(display.color, g.glow.value)

            letter_surface = font.render(character.value, True, color)
            # TODO: center the text in the box
            display.screen.blit(letter_surface, pos.spot)