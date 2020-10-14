#include <stdio.h>

int max_distance(int seats[], int length)
{
    int maxDistance = 0;
    int indexes[10];
    int takenSeats = 0;
    int i = 0;
    while (i < length)
    {
        if (seats[i] == 1)
        {
            indexes[takenSeats] = i;
            takenSeats++;
        }
        i++;
    }

    int startIndex = 0;
    int endIndex = 0;
    int maxDist = 0;

    // check for first index
    if (indexes[0])
    {
        startIndex = -1;
        endIndex = indexes[0];
        maxDist = indexes[0];
    }

    // in between indexes
    int i = 0;
    while (i < takenSeats - 1)
    {
        int i1 = indexes[i];
        int i2 = indexes[i + 1];
        int difference = 0;

        difference = i2 - i1 - 1;
        if (maxDist < difference)
        {
            startIndex = i1;
            endIndex = i2;
            maxDist = difference;
        }
        i++;
    }

    // check for endingIndex
    if (indexes[takenSeats - 1] != length - 1)
    {

        if (maxDist < (length - indexes[takenSeats - 1]))
        {
            maxDist = length - indexes[takenSeats - 1];
            startIndex = indexes[takenSeats - 1];
            endIndex = length;
        }
    }

    //printf("startIndex: %i\nendIndex: %i\nmaxDist: %i\n", startIndex, endIndex, maxDist);

    // case where max distance is from the start of seats
    if (startIndex == -1)
        return endIndex;

    // case whree max distance is from the end of seats
    if (endIndex == length)
        return length - 1 - startIndex;

    // in between
    if (maxDist % 2)
    {
        maxDistance = (endIndex - startIndex) / 2;
    }
    else
    {
        maxDistance = maxDist / 2 + 1;
    }

    return maxDistance;
}

int main()
{
    int seats[] = {1, 0, 0, 1, 0, 0, 1};
    int length = sizeof(seats) / sizeof(seats[0]);
    printf("max_distance = %d", max_distance(seats, length));
    return 0;
}