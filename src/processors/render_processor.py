"""
Render Processor Module
"""
import esper


from components.character import Character
from components.display import Display
from components.font_size import FontSize
from components.fonts import Fonts
from components.glow import Glow
from components.position import Position
from domain import gfx


class RenderProcessor(esper.Processor):
    """
    Render Processor
    """

    def process(self, *_, **__):
        _, display = esper.get_component(Display)[0]
        display.screen.fill(display.background_color)
        _, fonts = esper.get_component(Fonts)[0]
        for _, (pos, character, font_size, g) in esper.get_components(
                Position, Character, FontSize, Glow):
            font = gfx.get_font_from_size(fonts, font_size)
            if font is None:
                continue
            color = gfx.adjust_color_lightness(display.color, g.glow.value)

            letter_surface = font.render(character.value, True, color)
            display.screen.blit(letter_surface, pos.spot)
