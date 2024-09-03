#include <SFML/Graphics.hpp>
#include <cmath>
#include "iostream"

using namespace sf;
using namespace std;

const int W = 1920;
const int H = 1080;

int main()
{
    RenderWindow window(VideoMode(W, H), "Function graph!");
    Font font;
    font.loadFromFile("arial.ttf");

    Text text;
    text.setFont(font);
    text.setCharacterSize(10);
    text.setFillColor(Color::Black);

    Text text1;
    text1.setFont(font);
    text1.setCharacterSize(16);
    text1.setFillColor(Color::Black);


    int x0 = W / 2;
    int y0 = H / 2;

    CircleShape point(1.f);
    point.setFillColor(Color::Blue);

    CircleShape point1(1.f);
    point1.setFillColor(Color::Red);

    float c = 1000;
    int mass = 50 * c;
    int sc = 15;

    RectangleShape line[400];
    for (int i = 0; i < 400; i++) {
        line[i].setSize(Vector2f(1, 10));
        line[i].setFillColor(Color::Black);
        if (i < 200) {
            if (i < 100)
                line[i].setPosition(x0 - (i - 30) * sc, y0 - 10);
            else
                line[i].setPosition(x0 + (i - 70) * sc, y0 - 10);
        }
        else {
            line[i].setRotation(90);
            if (i < 300)
                line[i].setPosition(x0 + 10, y0 + (i - 300) * sc);
            else
                line[i].setPosition(x0 + 10, y0 + (i - 299) * sc);
        }
    }

    RectangleShape line_vertical;
    line_vertical.setSize(Vector2f(1, 112));
    line_vertical.setFillColor(Color::Red);

    RectangleShape line_horizontal;
    line_horizontal.setSize(Vector2f(1, 613));
    line_horizontal.setFillColor(Color::Red);
    line_horizontal.setRotation(90);

    int numbers_horizontal[114];
    int numbers_vertical[72];

    for (int i = 0; i < 72; i++){
        numbers_vertical[i] = i - 36;
    }
    for (int i = 0; i < 114; i++){
        numbers_horizontal[i] = i -50;
    }

    RectangleShape OsX(Vector2f(W, 1));
    OsX.setFillColor(Color::Black);
    OsX.setPosition(0, y0);

    RectangleShape OsY(Vector2f(1, H));
    OsY.setFillColor(Color::Black);
    OsY.setPosition(x0, 0);

    RectangleShape strel[4];
    for (int i = 0; i < 4; i++) {
        strel[i].setSize(Vector2f(1, 25));
        strel[i].setFillColor(Color::Black);

        if (i < 2)
            strel[i].setPosition(x0, 0);
        else
            strel[i].setPosition(W, y0);
    }

    strel[0].setRotation(25);
    strel[1].setRotation(-25);
    strel[2].setRotation(60);
    strel[3].setRotation(-250);

    float max_y = 0;
    float max_x = 0;
    float x1 = 0;
    float y1 = 0;
    float max_cordinateX = 0;
    float max_cordinateY = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color::White);
        window.draw(OsX);
        window.draw(OsY);
        for (int i = 72; i >= 0; i--){
            if (numbers_vertical[i]==0||numbers_vertical[i]==-36||numbers_vertical[i]==-50) continue;
            text.setString(to_string(numbers_vertical[i]));
            text.setPosition(x0 + 15, y0 + 535- i * sc);
            window.draw(text);
        }
        for (int i = 50; i < 114; i++){
            if (numbers_horizontal[i]==0||numbers_horizontal[i]==1) continue;
            text.setString(to_string(numbers_horizontal[i]));
            if (i>50&&i<60) {
                text.setPosition(x0 + i * sc - 753, y0 - 21);
            }
            else{
                text.setPosition(x0 + i * sc - 755, y0 - 21);
            }
            window.draw(text);
        }
        for (int i = 0; i < 4; i++)
            window.draw(strel[i]);
        for (int i = 0; i < 400; i++) {
            if ( i == 264) continue;
            window.draw(line[i]);
        }
        for (int i = 0; i < mass; i++) {
            float x = 3 * (M_PI / 2) + i / c;
            float y = sin(x / 2) * sin(x / 2) * sin(x / 2) + sqrt(x);
            x1 = x0 + x * sc;
            y1 = y0 - y * sc;
            point.setPosition(x1, y1);
            window.draw(point);
            if (max_y < y){
                max_y = y;
                max_x = x;
                max_cordinateX = x1;
                max_cordinateY = y1;
            }
            if (x > 16 * M_PI) break;
        }
        point1.setPosition(max_cordinateX, max_cordinateY);
        window.draw(point1);
        line_vertical.setPosition(max_cordinateX, max_cordinateY);
        window.draw(line_vertical);
        line_horizontal.setPosition(max_cordinateX, max_cordinateY);
        window.draw(line_horizontal);
        text1.setPosition(x0 + 600, y0 - 460);
        text1.setString("Maximum of function [3PI/2, 16PI] is: " + to_string(max_y));
        window.draw(text1);
        text1.setPosition(x0 + 600, y0 - 430);
        text1.setString("Maximum of function was on point x = " + to_string(max_x));
        window.draw(text1);
        window.display();
    }
    return 0;
}