#include "multithreading.h"

/**
 * blur_portion - method blurs a portion of an image using a Gaussian Blur,
 * 		  use id int property for boundary control. 
 * @portion: points to a data struct described in the project requirements
 */
void blur_portion(blur_portion_t const *portion)
{
	size_t rowstart, rowend; /* img pixel id boundaries within kernel matrix */
	size_t pixelsum = portion->img->w * portion->img->h;
	size_t idrow, idcol = 0, idsum;

	rowstart = (portion->img->w * portion->y) + portion->x;
	rowend = rowstart + portion->img->w * portion->h + portion->w;
	if (rowend > pixelsum)
		rowend = pixelsum;
	for (idrow = rowstart; idrow < rowend; idrow = idrow + portion->img->w)
	{
		for (; idcol < portion->w; idcol++)
		{
			idsum = idrow + idcol;
			if ((idcol > 0) && (idsum % portion->img->w == 0))
				break;
			pixelblur(portion, idsum);
		}
	}
}

/**
 * cutting_edge - function to define the edge of the matrix
 * @portion: points to a data struct described in the project requirements
 * Return: 0 if not the edge, 1 if it is the edge 
 */
int cutting_edge(blur_portion_t const *portion, )
{
	;

}


void pixelblur(blur_portion_t const *portion, size_t pixid)
{
	size_t i = 0, j = 0;
	pixel_t *pixxy;
	float weight, weightsum = 0;

	for (; i < portion->kernel->size; i++)
	{
		for (; j < portion->kernel->size; j++)
		{
			;
		}
	}
	;
}
