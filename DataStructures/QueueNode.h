#ifndef QUEUENODE_H 
#define QUEUENODE_H

typedef char ItemType;

struct QueueNode
{
	ItemType info;
	QueueNode* next;
};

#endif