"""
Entry Point
"""
import sys
import logging

import esper
import pygame

from matrix_game_pygame.components.display import Display
from matrix_game_pygame.components.font_size import FontSizes
from matrix_game_pygame.components.velocity import Velocity
from matrix_game_pygame.domain import gfx, rng, seeds
from matrix_game_pygame.processors.movement_processor import MovementProcessor
from matrix_game_pygame.processors.render_processor import RenderProcessor
from matrix_game_pygame.processors.rotation_processor import RotationProcessor


def main():
    """
    Main Entry-point
    """
    try:
        logging.basicConfig(level=logging.DEBUG)
        # setup display engine
        pygame.init()
        clock = pygame.time.Clock()
        screen_size = gfx.get_screen_size()
        screen = gfx.create_screen(screen_size)
        background_color = (0, 0, 0)
        font_color = rng.get_random_color()
        letter_width = gfx.get_letter_width(FontSizes.MEDIUM)
        # add entities with components
        seeds.seed_fonts()
        seeds.seed_display(
            screen=screen,
            screen_size=screen_size,
            background_color=background_color,
            font_color=font_color)
        cols = int(screen_size[0] / letter_width)
        seeds.seed_rain(cols, letter_width, screen_size[1])

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
                            logging.debug("KeyPress [space]`")
                            _, display = esper.get_component(Display)[0]
                            display.color = rng.get_random_color()
                        case pygame.K_UP:
                            logging.debug("KeyPress [up]")
                            for _, (v) in esper.get_component(Velocity):
                                # v.speed /= 2
                                speed = v.speed - 1
                                if speed >= 0:
                                    v.speed = speed
                                    #v.speed /= 10.0
                        case pygame.K_DOWN:
                            logging.debug("KeyPress [down]")
                            for _, (v) in esper.get_component(Velocity):
                                # v.speed *= 2
                                speed = v.speed + 1
                                if speed <= 100:
                                    v.speed = speed
                                    #v.speed *= 10.0
                        case _:
                            pass

            # run systems
            esper.process()

            # apply rendering
            pygame.display.update()
            clock.tick(60)

    # pylint: disable=broad-exception-caught
    except Exception as ex:
        print(str(ex))
        sys.exit(1)


if __name__ == "__main__":
    main()
