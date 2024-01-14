void deleteNode(node* t) {
    t->num = t->next->num;
    t->next = t->next->next;
    return;
}