#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESSES 100

struct Block
{
    int size; // Size of block
    int free; // 1 if block is free, 0 otherwise
};

struct Process
{
    char name; // Process name
    int size;  // Size of process
};

struct Block blocks[MAX_BLOCKS];
struct Process processes[MAX_PROCESSES];

int num_blocks = 0;
int num_processes = 0;

// Function to add a new memory block
void addBlock(int size)
{
    blocks[num_blocks].size = size;
    blocks[num_blocks].free = 1;
    num_blocks++;
}

// Function to add a new process
void addProcess(char name, int size)
{
    processes[num_processes].name = name;
    processes[num_processes].size = size;
    num_processes++;
}

void bestFit()
{
    int i, j, best_block;

    printf("\nBest Fit:\n");

    for (i = 0; i < num_processes; i++)
    {
        best_block = -1;
        for (j = 0; j < num_blocks; j++)
        {
            if (blocks[j].free == 1 && blocks[j].size >= processes[i].size)
            {
                if (best_block == -1 || blocks[j].size < blocks[best_block].size)
                    best_block = j;
            }
        }

        if (best_block != -1)
        {
            printf("Process %c allocated to Block %d\n", processes[i].name, best_block + 1);
            blocks[best_block].free = 0;
            blocks[best_block].size -= processes[i].size;
        }
        else
            printf("Process %c cannot be allocated to any block\n", processes[i].name);
    }

    for (i = 0; i < num_blocks; i++)
    {
        if (blocks[i].free == 1)
            printf("Block %d is unused\n", i + 1);
        else
            printf("Block %d has %d bytes of internal fragmentation\n", i + 1, blocks[i].size);
    }
}

int main()
{
    addBlock(200);
    addBlock(100);
    addBlock(150);
    addProcess('A', 100);
    addProcess('B', 50);
    addProcess('C', 25);
    addProcess('D', 75);

    bestFit();

    return 0;
}
