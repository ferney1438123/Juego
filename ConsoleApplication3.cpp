#include "pch.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>



#define ScreenWidth 800
#define ScreenHeight 600

int main()
	{
	al_init();
	ALLEGRO_DISPLAY *display;

	enum Direction{DOWN, LEFT,RIGHT, UP};
	const float FPS = 60;

	
	display = al_create_display(ScreenWidth, ScreenHeight);


	al_set_window_position(display, 200, 200);

	bool done = false, draw = true;
	float x = 10, y = 10, moveSpeed = 5;
	int dir = DOWN;

	al_install_keyboard();
	al_init_image_addon();
	//al_init_primitives_addon();


	ALLEGRO_KEYBOARD_STATE keyState;
	
	ALLEGRO_BITMAP *player = al_load_bitmap("test.png");
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);
	

	while (!done)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		else if  (events.type == ALLEGRO_EVENT_TIMER)
		{
			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
			
			{ y += moveSpeed;
			dir;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_UP))
			{
				y -= moveSpeed;
				dir = UP;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			{
				x += moveSpeed;
				dir = RIGHT;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			{
				x -= moveSpeed;
				dir = LEFT;
			}

			draw = true;
		}
		if (draw)
		{
			al_draw_bitmap(player, x, y, NULL);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
		
		
	}
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_bitmap(player);
	al_destroy_event_queue(event_queue);
	return 0;
}
	
