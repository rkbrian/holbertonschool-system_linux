#ifndef MULTITHREADING_H
#define MULTITHREADING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include "list.h"

pthread_mutex_t mymutex; /* for tprintf preventing race conditions */
pthread_mutex_t task_mutex; /* for tasks of prime factor printing */

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

/* Prime Factor V2 Structs */
typedef void *(*task_entry_t)(void *);

/**
 * enum task_status_e - Task statuses
 *
 * @PENDING: Task is pending
 * @STARTED: Task has been started
 * @SUCCESS: Task has completed successfully
 * @FAILURE: Task has completed with issues
 */
typedef enum task_status_e
{
    PENDING = 0,
    STARTED,
    SUCCESS,
    FAILURE
} task_status_t;

/**
 * struct task_s - Executable task structure
 *
 * @entry:  Pointer to a function to serve as the task entry
 * @param:  Address to a custom content to be passed to the entry function
 * @status: Task status, default to PENDING
 * @result: Stores the return value of the entry function
 * @lock:   Task mutex
 * @service_id: static variable for coming-in order
 */
typedef struct task_s
{
    task_entry_t    entry;
    void        *param;
    task_status_t   status;
    void        *result;
    pthread_mutex_t lock;
    unsigned int service_id; /* not provided in the problem, I added */
} task_t;

/* functions in main */
void *_thread_entry(__attribute__((unused))void *arg);
void load_kernel(kernel_t *kernel, char const *file);
void load_image(img_t *img, char const *file);
void img_copy(img_t *dest, img_t const *src);
void write_image(img_t const *img, char const *file);
void *exec_tasks(list_t const *tasks);
void print_factors(char const *s, list_t const *factors);
/* target functions */
void *thread_entry(void *arg);
int tprintf(char const *format, ...);
void blur_portion(blur_portion_t const *portion);
int cutting_edge(blur_portion_t const *portion, int pixid, int nei, int ps); /*my function*/
void pixelblur(blur_portion_t const *portion, size_t pixid, size_t pixelsum); /*my function*/
list_t *prime_factors(char const *s);
void *_thread_entry(__attribute__((unused))void *arg);
void init_mymutex(void) __attribute__((constructor)); /*my function*/
void end_mymutex(void) __attribute__((destructor)); /*my function*/
void print_task_result(task_t *task);
task_t *create_task(task_entry_t entry, void *param);
void destroy_task(task_t *task);
void init_tmutex(void) __attribute__((constructor)); /*my function*/
void end_tmutex(void) __attribute__((destructor)); /*my function*/

#endif /* MULTITHREADING_H */
