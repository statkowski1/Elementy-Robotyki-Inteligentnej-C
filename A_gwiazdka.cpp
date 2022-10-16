#include <iostream>
#include <cmath>

using namespace std;

    int start_x;
    int start_y;
    int meta_x;
    int meta_y;
    int rozmiar_x;
    int rozmiar_y;

float z_2(float liczba)
{
    return (float)((int)(liczba*100))/100;
}

int min_x(float value_f[8][8], int use[8][8])
{
    double minn = 100000;
    int wynik;
    for(int i=0; i<rozmiar_x; i++)
    {
        for(int j=0; j<rozmiar_y; j++)
        {
            if(minn>=value_f[i][j] && value_f[i][j]!=0 && use[i][j]!=1 && value_f[i][j]!=-1)
            {
                minn = value_f[i][j];
                wynik = i;
            }
        }
    }
    return wynik;
}

int min_y(float value_f[8][8], int use[8][8])
{
    double minn = 100000;
    int wynik;
    for(int i=0; i<rozmiar_x; i++)
    {
        for(int j=0; j<rozmiar_y; j++)
        {
            if(minn>=value_f[i][j] && value_f[i][j]!=0 && use[i][j]!=1 && value_f[i][j]!=-1)
            {
                minn = value_f[i][j];
                wynik = j;
            }
        }
    }
    return wynik;
}

int g(int way[8][8], int x, int y, int start_x, int start_y) //oblicza g w f
{
    int wx = x;
    int wy = y;
    int wynik = 0;
    //cout << wx << ":" << wy << endl;
    while(wx!=start_x || wy!=start_y)
    {
        if(way[wx][wy]==1) //prawo
        {
            wy = wy - 1;
            wynik += 1;
        }
        if(way[wx][wy]==2) //dó³
        {
            wx = wx - 1;
            wynik += 1;
        }
        if(way[wx][wy]==3) //lewo
        {
            wy = wy + 1;
            wynik += 1;
        }
        if(way[wx][wy]==4) //góra
        {
            wx = wx + 1;
            wynik += 1;
        }
    }
    return wynik;
}

int main()
{
    start_x = 0;
    start_y = 0;
    meta_x = 4;
    meta_y = 2;
    rozmiar_x = 8;
    rozmiar_y = 8;

    int way[8][8] = {};
    float f_value[8][8] = {};
    int use[8][8] = {};
    f_value[start_x][start_y] = 1;
    //przeszkody
    f_value[3][0] = -1;
    f_value[3][1] = -1;
    f_value[3][2] = -1;
    f_value[3][3] = -1;
    f_value[3][4] = -1;
    f_value[4][4] = -1;
    while(way[meta_x][meta_y]==0)
    {
        int minX = min_x(f_value, use);
        int minY = min_y(f_value, use);

        if(minY+1<rozmiar_y && way[minX][minY+1]==0 && f_value[minX][minY+1]!=-1) //w prawo
        {
            way[minX][minY+1] = 1;
            f_value[minX][minY+1] = g(way, minX, minY+1, start_x, start_y) + z_2(sqrt((minX-meta_y)*(minX-meta_x)+(minY+1-meta_y)*(minY+1-meta_y)));
        }
        if(minX+1<rozmiar_x && way[minX+1][minY]==0 && f_value[minX+1][minY]!=-1) //w dól
        {
            way[minX+1][minY] = 2;
            f_value[minX+1][minY] = g(way, minX+1, minY, start_x, start_y) + z_2(sqrt((minX+1-meta_x)*(minX+1-meta_x)+(minY-meta_y)*(minY-meta_y)));
        }
        if(minY-1>0 && way[minX][minY-1]==0 && f_value[minX][minY-1]!=-1) //w lewo
        {
            way[minX][minY-1] = 3;
            f_value[minX][minY-1] = g(way, minX, minY-1, start_x, start_y) + z_2(sqrt((minX-meta_x)*(minX-meta_x)+(minY-1-meta_y)*(minY-1-meta_y)));
        }
        if(minX-1>0 && way[minX-1][minY]==0 && f_value[minX-1][minY]!=-1) //w góre
        {
            way[minX-1][minY] = 4;
            f_value[minX-1][minY] = g(way, minX-1, minY, start_x, start_y) + z_2(sqrt((minX-1-meta_x)*(minX-1-meta_x)+(minY-meta_y)*(minY-meta_y)));
        }
        use[minX][minY] = 1;
    }

    for(int i=0; i<rozmiar_x; i++)
    {
        for(int j=0; j<rozmiar_y; j++)
        {
            cout << way[i][j] << ", ";
        }
        cout << endl;
    }

    //rysowanie planszy
    int plansza[8][8] = {};
    plansza[start_x][start_y] = 1;
    plansza[meta_x][meta_y] = 1;
    int x = meta_x;
    int y = meta_y;
    cout << endl;
    while(x!=start_x && y!=start_y)
    {
        if(way[x][y]==1)
        {
            y -= 1;
            plansza[x][y] = 1;
        }
        if(way[x][y]==2)
        {
            x -= 1;
            plansza[x][y] = 1;
        }
        if(way[x][y]==3)
        {
            y += 1;
            plansza[x][y] = 1;
        }
        if(way[x][y]==4)
        {
            x += 1;
            plansza[x][y] = 1;
        }
    }

    for(int i=0; i<rozmiar_x; i++)
    {
        for(int j=0; j<rozmiar_y; j++)
        {
            cout << plansza[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}