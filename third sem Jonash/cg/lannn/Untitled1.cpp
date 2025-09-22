#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int maxx, maxy, midx, midy;

void axis()
{
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}

void translation()
{
    int tx, ty;
    outtextxy(100, 20, "TRANSLATION");

    printf("Enter the Translation vector (x y): ");
    scanf("%d %d", &tx, &ty);

    // Original object
    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
    
    // Translated object
    bar3d(midx + 100 + tx, midy - 20 - ty, midx + 60 + tx, midy - 90 - ty, 20, 5);

    outtextxy(100, 100, "END OF PROGRAM. Goto terminal window");
}

void scaling()
{
    int sx, sy, sz;
    outtextxy(100, 20, "SCALING");

    printf("Enter the Scaling Factors (sx sy sz): ");
    scanf("%d %d %d", &sx, &sy, &sz);

    // Original object
    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);

    // Scaled object
    bar3d(midx + 100, midy - 20, midx + 100 - (40 * sx), midy - 20 - (70 * sy), 20 * sz, 5);

    outtextxy(100, 100, "END OF PROGRAM. Goto terminal window");
}

void rotation()
{
    int angle;
    float rad;
    int x1, y1, x2, y2;
    outtextxy(100, 20, "ROTATION");

    printf("Enter the Rotation angle (in degrees): ");
    scanf("%d", &angle);
    rad = angle * 3.14159 / 180;

    // Original coordinates
    int ox1 = 100, oy1 = 20;
    int ox2 = 60,  oy2 = 90;

    // Rotate coordinates
    x1 = ox1 * cos(rad) - oy1 * sin(rad);
    y1 = ox1 * sin(rad) + oy1 * cos(rad);
    x2 = ox2 * cos(rad) - oy2 * sin(rad);
    y2 = ox2 * sin(rad) + oy2 * cos(rad);

    // Original object
    bar3d(midx + ox1, midy - oy1, midx + ox2, midy - oy2, 20, 5);

    // Rotated object
    bar3d(midx + x1, midy - y1, midx + x2, midy - y2, 20, 5);

    outtextxy(100, 100, "END OF PROGRAM. Goto terminal window");
}

int main()
{
    int choice;
    printf("Menu driven program for 3D transformation\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setfillstyle(3, 25);
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    cleardevice();
    axis();

    outtextxy(100, 100, "ORIGINAL OBJECT");
    bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);

    getch();
    cleardevice();
    axis();

    switch (choice)
    {
        case 1:
            translation();
            break;
        case 2:
            scaling();
            break;
        case 3:
            rotation();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    getch();
    closegraph();
    return 0;
}
