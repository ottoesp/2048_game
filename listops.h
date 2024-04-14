#include <stdlib.h>
#include <assert.h>

typedef struct node node_t;

struct node {
	void *data;
	node_t *next;
};

typedef struct list list_t;

list_t *make_empty_list(void);
int is_empty_list(list_t *list);
void free_list(list_t *list);
list_t *insert_at_head(list_t *list, void *value);
list_t *insert_at_foot(list_t *list, void *value);
void *get_head(list_t *list);
node_t *get_head_node(list_t *list);