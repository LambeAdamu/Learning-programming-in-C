Lambe Emmanuel
SC24C246

void enqueue(Queue *q, Item it)
{
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    int head = q->head;
    int tail = q->tail;
    int insertp = head;
    int j, k;

    // find insertion position based on priority 
    for (j = tail; j >= head; j--)
    {
        if (it.priority > q->elements[j].priority)
            break;
    }
    insertp = j + 1;

// shift elements to the right 
    for (k = tail; k >= insertp; k--)
    {
        q->elements[k + 1] = q->elements[k];
    }
// insert new item 
    q->elements[insertp] = it;
    q->tail++;
    }