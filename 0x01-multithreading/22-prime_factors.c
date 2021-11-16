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
	newtask->service_id = id;
	id++;
	return (newtask);
}

/**
 * destroy_task - function to destroy a task
 * @task: pointer to the task to destroy
 */
void destroy_task(task_t *task)
{
	if (task)
	{
		list_destroy(task->result, free);
		free(task->result);
		free(task);
	}
}

/**
 * exec_tasks - function serves as a thread entry,
 * can safely return NULL as its return value will not be retrieved
 * @tasks: pointer to the list of tasks to be executed
 * Return: void pointer of NULL as its return value will not be retrieved
 */
void *exec_tasks(list_t const *tasks)
{
	int id, status, status_flag = 0; /* 0 for pending task */
	node_t *curr = NULL; /* current node */
	void *newres;
	task_t *currta;

	if (!tasks)
		pthread_exit(NULL);
	while (status_flag == 0)
	{
		curr = tasks->head, currta = ((task_t *)curr->content), status_flag++;
		while (curr)
		{
			status_flag = 0, pthread_mutex_lock(&currta->lock);
			status = currta->status, pthread_mutex_unlock(&currta->lock);
			if (status == PENDING)
			{
				id = currta->service_id, tprintf("[%02u] Started\n", id);
				newres = currta->entry(currta->param);
				pthread_mutex_lock(&currta->lock), currta->status = STARTED;
				currta->result = newres, pthread_mutex_unlock(&currta->lock);
				if (newres)
				{
					pthread_mutex_lock(&currta->lock), currta->status = SUCCESS;
					pthread_mutex_unlock(&currta->lock), tprintf("[%02u] Success\n", id);
				}
				else
				{
					pthread_mutex_lock(&currta->lock), currta->status = FAILURE;
					pthread_mutex_unlock(&currta->lock), tprintf("[%02u] Failure\n", id);
				}
			}
			curr = curr->next;
			if (curr)
				currta = ((task_t *)curr->content);
		}
	}
	return (NULL);
}

/**
 * init_tmutex - use pthread_mutex_init method as mutex constructor
 */
void init_tmutex(void)
{
	pthread_mutex_init(&task_mutex, NULL);
}

/**
 * end_tmutex - use pthread_mutex_destroy method as mutex destructor
 */
void end_tmutex(void)
{
	pthread_mutex_destroy(&task_mutex);
}
