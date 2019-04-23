#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

#define CHECK_INSERT 0    // "插入"动作的检测开关(0，关闭；1，打开)
#define CHECK_DELETE 0    // "删除"动作的检测开关(0，关闭；1，打开)
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int b[] = {40, 70, 50, 80, 100, 90, 30, 80, 90};
    int i, ilen=LENGTH(a);
    RBRoot *root=NULL;
    Node *search_node=NULL, *tmp_node = NULL;

    if(!(search_node = (Node *)malloc(sizeof(Node)))) {
        exit(-1);
    }

    root = create_rbtree();
    printf("== 原始数据: ");
    for(i=0; i<ilen; i++)
        printf("%d~%d\t", a[i], b[i]);
    printf("\n");

    for(i=0; i<ilen; i++)
    {
        insert_rbtree(root, a[i], b[i]);
#if CHECK_INSERT
        printf("== 添加节点: %d\n", a[i]);
        printf("== 树的详细信息: \n");
        print_rbtree(root);
        printf("\n");
#endif
    }

    // printf("== 前序遍历: ");
    // preorder_rbtree(root);

    // printf("\n== 中序遍历: ");
    // inorder_rbtree(root);

    // printf("\n== 后序遍历: ");
    // postorder_rbtree(root);
    // printf("\n");

    // if (rbtree_minimum(root, &i)==0)
    //     printf("== 最小值: %d\n", i);
    // if (rbtree_maximum(root, &i)==0)
    //     printf("== 最大值: %d\n", i);
    
    search_node->key = 0;
    search_node->high = 9;
    tmp_node = interval_search(root->node, search_node);
    if(tmp_node) {
        printf("%d~%d\n", tmp_node->key, tmp_node->high);
    }
    else {
        printf("No node match!\n");
    }

    printf("== 树的详细信息: \n");
    print_rbtree(root);
    printf("\n");

    delete_rbtree(root, 10);

    tmp_node = interval_search(root->node, search_node);
    if(tmp_node) {
        printf("%d~%d\n", tmp_node->key, tmp_node->high);
    }
    else {
        printf("No node match!\n");
    }


#if CHECK_DELETE
    for(i=0; i<ilen; i++)
    {
        delete_rbtree(root, a[i]);

        printf("== 删除节点: %d\n", a[i]);
        if (root)
        {
            printf("== 树的详细信息: \n");
            print_rbtree(root);
            printf("\n");
        }
    }
#endif

    destroy_rbtree(root);
    return 0;
}
