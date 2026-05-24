#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char direction;
int height = 10, width = 20;
int x = (width / 2) - 2, y = (height / 2) - 2;
    //food spawning system
   
int fx;
int fy;

void draw()
{
    for (int i = 0; i < width; i++)
    { // draws the top border
        cout << "#";
    }
    cout << endl;
    for (int j = 0; j < height - 2; j++)
    {
        cout << "#";
        for (int k = 0; k < width - 2; k++)
        {
            if (k == x && j == y)
            {
                cout << "O";
            }else if(k==fx&&j==fy){
                cout<<"@";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < width; i++)
    { // draws the bottom border
        cout << "#";
    }
    cout << endl;
}
int main()
{
    srand(time(0));
    fx = rand() % (width - 2);
    fy = rand() % (height -2);
    //overlap of food and snake check
    while(fx==x&&fy==y){
        fx = rand() % (width - 2);
        fy = rand() % (height -2);
    }
    while (true)
    {
        system("cls");

        draw();
        cout << "Enter direction (W/A/S/D): ";
        cin >> direction;
        if (direction == 'w' || direction == 'W')
        {
            y--;
        }
        else if (direction == 's' || direction == 'S')
        {
            y++;
        }
        else if (direction == 'a' || direction == 'A')
        {
            x--;
        }
        else if (direction == 'd' || direction == 'D')
        {
            x++;
        }
        // check for wall collision
        if(x<0||x>=width-2||y<0||y>=height-2){
            cout<<"Game Over!"<<endl;
            break;
        }
        
    }
    return 0;
}