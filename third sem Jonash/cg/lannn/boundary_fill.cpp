#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>

// Boundary Fill Algorithm
void boundaryFill(int x, int y, int fill_color, int boundary_color)
{
    int current = getpixel(x, y);
    if (current != boundary_color && current != fill_color)
    {
        putpixel(x, y, fill_color);
        delay(0.1);
        // 4-connected + diagonals (8-connected)
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
        boundaryFill(x + 1, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill(x - 1, y - 1, fill_color, boundary_color);
    }
}
// Flood Fill Algorithm
void floodFill(int x, int y, int new_color, int old_color)
{
    if (getpixel(x, y) == old_color)
    {
        putpixel(x, y, new_color);
        delay(0.1);
        // 4-connected + diagonals (8-connected)
        floodFill(x + 1, y, new_color, old_color);
        floodFill(x - 1, y, new_color, old_color);
        floodFill(x, y + 1, new_color, old_color);
        floodFill(x, y - 1, new_color, old_color);
        floodFill(x + 1, y + 1, new_color, old_color);
        floodFill(x - 1, y + 1, new_color, old_color);
        floodFill(x + 1, y - 1, new_color, old_color);
        floodFill(x - 1, y - 1, new_color, old_color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    setcolor(WHITE);
    rectangle(100, 100, 300, 300); // drawing boundary

    int choice;
    printf("\nChoose Fill Algorithm:\n");
    printf("1. Boundary Fill\n");
    printf("2. Flood Fill\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // fill with RED and boundary is WHITE
        boundaryFill(150, 150, WHITE, LIGHTGRAY);
        break;

    case 2:
    {
        int x, y, old_color, new_color;
        printf("Enter seed point (x, y): ");
        scanf("%d %d", &x, &y);
        printf("Enter old color: ");
        scanf("%d", &old_color);
        printf("Enter new color: ");
        scanf("%d", &new_color);
        floodFill(x, y, new_color, old_color);
        break;
    }

    default:
        printf("Invalid choice!");
        break;
    }

    getch();
    closegraph();
    return 0;
}
