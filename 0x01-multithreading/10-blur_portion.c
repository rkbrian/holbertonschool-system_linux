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
			pixelblur(portion, idsum, pixelsum);
		}
	}
}

/**
 * cutting_edge - function to define the edges of the matrix
 * @portion: points to a data struct described in the project requirements
 * @pixid: pixel id
 * @nei: neighboring id
 * @ps: total number of pixels in the image
 * Return: 1 if not the edge, 0 if it is the edge
 */
int cutting_edge(blur_portion_t const *portion, int pixid, int nei, int ps)
{
	int idcol, neicol, halfsize = (int)(portion->kernel->size) / 2;

	if (nei < 0 || nei >= ps) /* out of boarder */
		return (0);
	idcol = pixid % (int)(portion->img->w);
	neicol = nei % (int)(portion->img->w);
	if (idcol + halfsize >= (int)(portion->img->w))
		return (neicol - halfsize >= 0);
	if (idcol - halfsize < 0)
		return (neicol + halfsize < (int)(portion->img->w));
	return (1);
}

/**
 * pixelblur - function to blur the pixel with Gaussian Blur
 * @portion: points to a data struct described in the project requirements
 * @pixid: pixel id
 * @pixelsum: total number of pixels in the image
 */
void pixelblur(blur_portion_t const *portion, size_t pixid, size_t pixelsum)
{
	size_t i = 0, j = 0;
	pixel_t *pixie;
	int nei; /* neighboring id*/
	float weight, weightsum = 0, myr = 0, myg = 0, myb = 0;

	nei = pixid - (portion->kernel->size / 2) * (portion->img->w + 1);
	for (; i < portion->kernel->size; i++)
	{
		for (; j < portion->kernel->size; j++)
		{
			/* neighboring id to control */
			if (cutting_edge(portion, (int)pixid, nei + j, (int)pixelsum) != 0)
			{
				weight = portion->kernel->matrix[i][j];
				pixie = &(portion->img->pixels[nei + j]);
				myr = myr + pixie->r * weight;
				myg = myg + pixie->g * weight;
				myb = myb + pixie->b * weight;
				weightsum = weightsum + weight;
			}
		}
		nei = nei + portion->img->w;
	}
	pixie = &(portion->img_blur->pixels[pixid]);
	pixie->r = (int)(myr / weightsum);
	pixie->g = (int)(myg / weightsum);
	pixie->b = (int)(myb / weightsum);
}
