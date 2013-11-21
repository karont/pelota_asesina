/**ALVARO QUESADA PIMENTEL**/
#ifndef LAPIZ_H
#define LAPIZ_H
#include "PV2D.h"
class Lapiz
{
public:
	Lapiz(void);
	//~Lapiz();
	Lapiz(PV2D new_pos, GLdouble new_dir):pos(new_pos), dir(new_dir){}

	void turn(const GLdouble &a);
	void forward(const GLdouble &dist,const bool &draw);

	void moveTo(const PV2D &p, const bool &draw);
	void turnTo(const GLdouble &a);
	PV2D getpos(void) const;
	GLdouble getdir(void)const;
private:
	PV2D pos;
	GLdouble dir;
};

#endif // !LAPIZ_H

