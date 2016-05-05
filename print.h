#ifndef __PRINT__
#define __PRINT__
#define x_picture 50

void draw_window(int x, int y);

typedef struct s_elem {
	int x;
	int y;
	MLV_Image *image;
	void (*draw)(struct s_elem *);
} t_elem;

MLV_Image *load_image(char *, int, int);
void draw(t_elem *);


#endif
