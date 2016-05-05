#include <MLV/MLV_all.h>
#include <stdio.h>
#include "print.h"
#include "missile.h"


void missile(t_elem *tir)
{
	MLV_draw_image(tir->image, tir->x, tir->y);
}

t_elem* create_missile (t_elem* Missile)
{
	Missile->x = x_picture;
	Missile->y = 600;
	Missile->image = load_image("glacon.png", 25, 25);
	Missile->draw = missile;

	return Missile;
}
