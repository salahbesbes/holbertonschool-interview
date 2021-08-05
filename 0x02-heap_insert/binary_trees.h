/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;

} binary_tree_t;

typedef struct sort_node_child
{
    int n;
    struct sort_node_child *greatest;
    struct sort_node_child *greater;
    struct sort_node_child *smallest;

} sort_nodes_t;

typedef struct binary_tree_s heap_t;
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
void sort_nodes(heap_t **parent);
