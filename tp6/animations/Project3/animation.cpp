#include "animation.h"

animation::animation(char name,string pref,unsigned int im_cant,double per, double vel)
{
	anim_id = name;
	anim_prefix = pref;
	anim_cant_img = im_cant;
	anim_period=per;
	speed=vel;
}

char& animation::get_anim_id(void)
{
	return anim_id;
}

double & animation::get_anim_per(void)
{
	return anim_period;
	// TODO: insertar una instrucci�n return aqu�
}

double & animation::get_speed(void)
{
	return speed;
	// TODO: insertar una instrucci�n return aqu�
}

string& animation::get_anim_prefix(void)
{
	return anim_prefix;
}

unsigned int& animation::get_anim_cant_img(void)
{
	return anim_cant_img;
}

void animation::play_anim(char anim_type,int& i, float& k, float MAX_SCREEN_WIDTH, float MAX_SCREEN_HEIGHT,bool& sense,unsigned int img_qnt)
{
	switch (anim_type) {
	case 'A':
	case 'D':
	case 'E':
	case 'F':
		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_draw_bitmap(p2anim_lib[i], k, MAX_SCREEN_HEIGHT / 10.0, sense); // sobre 10.0 para que la imagen se centre
		al_flip_display();

		if (i < get_anim_cant_img() - 1) { // como son n imagenes entonces 
			i++;							// tengo que cortar en n-1 imagenes
		}
		else {
			i = 0;
		}
		if (k < (MAX_SCREEN_WIDTH - k)) {
			k += get_speed();
		}
		else {
			k = 0;
		}
		break;
	case 'B':
	case 'C':
		k = 1; // para que no corte 
		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_draw_bitmap(p2anim_lib[i], k, MAX_SCREEN_HEIGHT / 10.0, sense); // sobre 10.0 para que la imagen se centre
		al_flip_display();
		if (i < img_qnt-1) {
			i++;
		}else {
			i = 0;
			k = 0;
		}
		break;
	default:
		break;
	}

}


animation::~animation()
{
}
