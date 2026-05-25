#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char direction;
int height = 10, width = 20;
int x = (width / 2) - 2, y = (height / 2) - 2;
//snake body and tail system
const int maxtail = 100;
int tailx[maxtail], taily[maxtail];
int taillength=0;
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
            {bool printed  = false;
                for(int i=0; i<taillength;i++){
                    if(tailx[i]==k&&taily[i]==j){
                        cout<<"o";
                        printed = true;
                        break;
                    }
                }
                if(!printed){
                    cout << " ";
                }
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
        //body coordinate setting
        for(int i=taillength-1;i>0;i--){
            tailx[i] = tailx[i-1];
            taily[i] = taily[i-1];
        }
        tailx[0] = x;
        taily[0] = y;
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
        //food capture and new generation
        if(x==fx&&y==fy){
            taillength++;
            fx = rand() % (width - 2);
            fy = rand() % (height -2);
            while(fx==x&&fy==y){
                fx = rand() % (width - 2);
                fy = rand() % (height -2);
            }
        }
        // check for wall and body collision
        if(x<0||x>=width-2||y<0||y>=height-2){
            cout<<"Game Over!"<<endl;
            break;
        }
        for(int i=1;i<taillength;i++){
            if(tailx[i]==x&&taily[i]==y){
                cout<<"Game Over!"<<endl;
                return 0;
            }
        }
        
    }
    return 0;
}