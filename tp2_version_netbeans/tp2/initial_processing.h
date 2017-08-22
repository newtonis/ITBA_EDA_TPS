#ifndef MAIN_H
#define MAIN_H


typedef struct {
	double x0, y0, xf, yf;
	int xMax, yMax;
        int lStart , lEnd;
        double leftAngle , rightAngle;
}parameter_data; // to organize manderbrot input data


int parseCallback(char *key,char *data,void *userData);


#endif /* MAIN_H */

