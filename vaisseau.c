#include <MLV/MLV_all.h>
#include <stdio.h>
#include "print.h"
#include "vaisseau.h"

void vaisseau(t_elem *vaisseau) {
	MLV_draw_image(vaisseau->image, vaisseau->x, vaisseau->y);
}

t_elem* create_vaisseau(t_elem* Vaisseau)
{
	Vaisseau->x = x_picture;
	Vaisseau->y = 630;
	Vaisseau->image = load_image("Pingouin.png", 60, 60);
	Vaisseau->draw = vaisseau;

	return Vaisseau;
}
