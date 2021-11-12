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
 * cutting_edge - function to define the edge of the matrix
 * @portion: points to a data struct described in the project requirements
 * @pixid: pixel id
 * @pixelsum: total number of pixels in the image
 * Return: 0 if not the edge, 1 if it is the edge 
 */
int cutting_edge(blur_portion_t const *portion, size_t pixid, size_t pixelsum)
{
	int pixelsum = portion->img->w * portion->img->h;
	;

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
			if (cutting_edge(portion, pixid, pixelsum) == 0)
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
	pixie->r = (int)(r / weightsum);
	pixie->g = (int)(g / weightsum);
	pixie->b = (int)(b / weightsum);
}
