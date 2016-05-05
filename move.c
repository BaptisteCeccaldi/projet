#include <MLV/MLV_all.h>
#include <stdio.h>
#include "print.h"
#include "vaisseau.h"
#include "ennemi.h"
#include "missile.h"

void Acceleration(t_elem *Vaisseau, int i, int PlusOuMoins){
	int j,k,n=0;
	for(j=0;j<i;j=j+15){
		Vaisseau->x+=PlusOuMoins;
		n++;
		for(k=0;k<n;k++){
			Vaisseau->x+=PlusOuMoins;
		}
	}
}
	
