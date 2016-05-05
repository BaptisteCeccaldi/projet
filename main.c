#include <MLV/MLV_all.h>
#include <stdio.h>
#include <time.h>
#include "print.h"
#include "vaisseau.h"
#include "ennemi.h"
#include "missile.h"
#include "move.h"

#define vitesse_defilement 1

int main(int argc, char const *argv[])
{
	MLV_Keyboard_button sym=MLV_KEYBOARD_NONE;
	MLV_Button_state state;
	MLV_Event event = MLV_NONE;
	int quit=0,i=1, flag_tir=0;
	int testX=0;
	int testY=rand() %650;
	int ennemy_x[4]={50, 240, 430, 620};

	MLV_create_window("Test", "test", 710, 710);
	draw_window(testX, testY);

	t_elem Vaisseau;
	t_elem ennemy;
	t_elem Missile; t_elem Missile2;

	create_vaisseau(&Vaisseau);
	create_ennemi(&ennemy);
	create_missile(&Missile); create_missile(&Missile2); 
	
	draw(&Vaisseau);

	srand(time(NULL));
	//MLV_change_frame_rate( 500 );
	
	// draw(&ennemy);
	
	do {
                event = MLV_get_event( &sym, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &state);
                switch( event ){
                        case MLV_NONE : // Aucun évènement récupéré	
                        
								/*ennemy.y = ennemy.y+5;
								if(ennemy.y > 700){
									ennemy.y = -100;
									ennemy.x = ennemy_x[rand() %4];
								}
								*/
								/*if(MLV_get_time() == 3000)
								{
									draw(&ennemy);
								}*/		
									
								testX += vitesse_defilement; // Affichage étoile 
								if(testX > 700){
									testX=0;
									testY=rand() %635;
								}
								
								if(flag_tir==2 )  // Tir 2
								{
									Missile.y=Missile.y-20;
									Missile2.y=Missile2.y-20;	
									
                                    if(Missile.y>0)
										draw(&Missile);
										
									 if(Missile2.y>0)	
										draw(&Missile2);
										
									if(Missile2.y<-30)
									{
										flag_tir=0;
										Missile.y=600;
										Missile2.y=600; // Faire une fonction reset qui prend pos collision en param (quand on ferra la gestion des collisions )
									}
								}
																
								if(flag_tir==1) // Tir 1
								{
									Missile.y=Missile.y-20;
									draw(&Missile);
									
									if(Missile.y<-30)
									{
										flag_tir=0;
										Missile.y=600; // Faire une fonction reset qui prend pos collision en param (quand on ferra la gestion des collisions )
									}
								}
								
								draw_window(testX, testY);
							//	draw(&ennemy);
								draw(&Vaisseau);			
                                break;
                        case MLV_KEY :  
								while((Vaisseau.x < 650 && MLV_get_keyboard_state( MLV_KEYBOARD_RIGHT ) == MLV_PRESSED )) // Bouge à droite
									{	
										if(MLV_get_keyboard_state( MLV_KEYBOARD_SPACE ) == MLV_PRESSED)
										{
												
											if(flag_tir == 0){
												Missile.x = Vaisseau.x;																	
												flag_tir=1;
											}
																				
										}						
										i++;
										Acceleration(&Vaisseau, i, 1);	
										
										testX += vitesse_defilement;
										if(testX > 700){
											testX=0;
											testY=rand() %635;
										}
																	
                                        if(flag_tir==1)
										{
											Missile.y=Missile.y-20;
											draw(&Missile);
											if(Missile.y<-30)
											{
												flag_tir=0;
												Missile.y=600;
											}
										}
										
										draw_window(testX, testY);
										draw(&Vaisseau);
										
                                  	
									}	
                                while( MLV_get_keyboard_state( MLV_KEYBOARD_LEFT ) == MLV_PRESSED && Vaisseau.x > 20) // Bouge à gauche
									{ 
										if(MLV_get_keyboard_state( MLV_KEYBOARD_SPACE ) == MLV_PRESSED)
										{
											if(flag_tir==0)
												Missile.x = Vaisseau.x;		
																				
                                            flag_tir=1;
																				
										}
										i++;
										Acceleration(&Vaisseau, i, -1);
										
										testX += vitesse_defilement;
										if(testX > 700){
											testX=0;
											testY=rand() %635;
										}
								
                                        if(flag_tir==1)
										{
											Missile.y=Missile.y-20;
											draw(&Missile);
											if(Missile.y<-30)
											{
												flag_tir=0;
												Missile.y=600;
											}
										}
										
										draw_window(testX, testY);
										draw(&Vaisseau);
										
										
										
									}
                                if( MLV_get_keyboard_state( MLV_KEYBOARD_SPACE ) == MLV_PRESSED  ){ // Tir 
									Missile.x = Vaisseau.x+17;	
									Missile2.x = Vaisseau.x+17;	
									
									if(flag_tir == 1)
									{
										flag_tir = 2;
									}
									if(flag_tir == 0)
									{
										flag_tir = 1;
									}								
								}
									    
                        default :
                                fprintf(stderr,"Erreur : la valeur de l'évènement récupéré est impossible.");
                }
            
                i=0;
                
        } while( ! quit );
        
	
	MLV_wait_seconds(10);
	return 0;
}
