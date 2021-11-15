#include "multithreading.h"

/**
 * create_task - function to create a task
 * @entry: pointer to the entry function of the task
 * @param: the parameter that will later be passed to the entry function
 * Return: a pointer to the created task structure
 */
task_t *create_task(task_entry_t entry, void *param)
{
	task_t *newtask = NULL;
	static unsigned int id;

	newtask = malloc(sizeof(task_t));
	if (!newtask)
		return (NULL);
	newtask->entry = entry;
	newtask->param = param;
	newtask->status = PENDING;
	newtask->result = NULL;
	newtask->lock = task_mutex;
	return (newtask);
}

/**
 * destroy_task - function to destroy a task
 * @task: 
 */
void destroy_task(task_t *task)
{
	if (task)
	{
		free(task);
	}
}

/**
 * exec_tasks - function serves as a thread entry,
 * can safely return NULL as its return value will not be retrieved
 * @tasks: pointer to the list of tasks to be executed
 */
void *exec_tasks(list_t const *tasks)
{
	;
}

/**
 * init_mymutex - use pthread_mutex_init method as mutex constructor
 */
void init_tmutex(void)
{
	pthread_mutex_init(&task_mutex, NULL);
}

/**
 * end_mymutex - use pthread_mutex_destroy method as mutex destructor
 */
void end_tmutex(void)
{
	pthread_mutex_destroy(&task_mutex);
}