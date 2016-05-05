#include <MLV/MLV_all.h>
#include <stdio.h>
#include <time.h>
#include "print.h"
#include "ennemi.h"

int ennemy_x[4]={50, 240, 430, 620};

void ennemi(t_elem *ennemy)
{		
	MLV_draw_image(ennemy->image, ennemy->x, ennemy->y);
}


t_elem* create_ennemi (t_elem* ennemy)
{
	ennemy->x = ennemy_x[rand() %4];
	ennemy->y = -100;
	ennemy->image = load_image("ennemi2.png", 60, 60);
	ennemy->draw = ennemi;

	return ennemy;
}
