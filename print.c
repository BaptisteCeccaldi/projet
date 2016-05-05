#include <MLV/MLV_all.h>
#include <stdio.h>
#include <time.h>
#include "print.h"

MLV_Image *load_image(char *file_path, int x, int y)
{
	MLV_Image *elem = MLV_load_image(file_path);
    MLV_resize_image_with_proportions(elem, x, y);

    return elem;

}

void draw(t_elem *elem) {
	elem->draw(elem);
	MLV_actualise_window();
}

void draw_window(int x, int y)
{
	MLV_clear_window(MLV_COLOR_BLACK);	
	MLV_Image *fond1;
	MLV_Image *fond2;
	MLV_Image *fond3;
	fond1 = MLV_load_image("espace1.png");
	fond2 = MLV_load_image("etoile1.png");
	fond3 = MLV_load_image("fond.png");

	/// CHOIX 1 /// 1 Image zoomé
//	MLV_resize_image(fond1,710, 1300);
//	MLV_draw_image(fond1, 0, x-550);
	
	/// CHOIX 2 /// fond noir + étoile, dans cette idée
/*	MLV_resize_image_with_proportions(fond2,50, 50);
	MLV_draw_image(fond2, 100,300+x);
	MLV_draw_image(fond2, 200,150+x);
	MLV_draw_image(fond2, 260,160+x);
	MLV_draw_image(fond2, 390,220+x);
	MLV_draw_image(fond2, 500,600+x);
	MLV_draw_image(fond2, 600,110+x);
*/

	/// CHOIX 3 /// truc fait à la base
	MLV_resize_image(fond3,710, 710);
	MLV_draw_image(fond3, 0, 0);
//	MLV_draw_image(fond2, y,x); // WAA trop beau sans resize
	MLV_resize_image_with_proportions(fond2,50, 50);
	MLV_draw_image(fond2, y,x);
	
	MLV_free_image(fond1);
	MLV_free_image(fond2);
	MLV_free_image(fond3);
}
