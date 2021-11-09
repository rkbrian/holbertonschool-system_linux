#ifndef MULTITHREADING_H
#define MULTITHREADING_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

/**
 * struct pixel_s - RGB pixel
 *
 * @r: Red component
 * @g: Green component
 * @b: Blue component
 */
typedef struct pixel_s
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

/**
 * struct img_s - Image
 *
 * @w:      Image width
 * @h:      Image height
 * @pixels: Array of pixels
 */
typedef struct img_s
{
    size_t w;
    size_t h;
    pixel_t *pixels;
} img_t;

/**
 * struct kernel_s - Convolution kernel
 *
 * @size:   Size of the matrix (both width and height)
 * @matrix: Kernel matrix
 */
typedef struct kernel_s
{
    size_t size;
    float **matrix;
} kernel_t;

/**
 * struct blur_portion_s - Information needed to blur a portion of an image
 *
 * @img:      Source image
 * @img_blur: Destination image
 * @x:        X position of the portion in the image
 * @y:        Y position of the portion in the image
 * @w:        Width of the portion
 * @h:        Height of the portion
 * @kernel:   Convolution kernel to use
 */
typedef struct blur_portion_s
{
    img_t const *img;
    img_t *img_blur;
    size_t x;
    size_t y;
    size_t w;
    size_t h;
    kernel_t const *kernel;
} blur_portion_t;

/* functions in main */
void *_thread_entry(__attribute__((unused))void *arg);
void load_kernel(kernel_t *kernel, char const *file);
void load_image(img_t *img, char const *file);
void img_copy(img_t *dest, img_t const *src);
void write_image(img_t const *img, char const *file);

/* target functions */
void *thread_entry(void *arg);
int tprintf(char const *format, ...);
void blur_portion(blur_portion_t const *portion);

#endif /* MULTITHREADING_H */
