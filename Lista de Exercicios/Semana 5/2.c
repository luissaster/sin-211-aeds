#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sChannel
{
    char channelName[64];
    int channelNumber;
} channel;
typedef struct sNode
{
    channel info;
    struct sNode *left;
    struct sNode *right;
} node;
int main(void)
{
    /* code */
    return 0;
}