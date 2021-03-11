//
//  TextGenerator.hpp
//  Typer++
//
//  Created by Dode Pep on 2/13/20.
//  Copyright © 2020 Dode. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
#include "ResourcePath.hpp"
using namespace sf;

class TextGenerator {
public:
    TextGenerator(int row);
    void draw(RenderWindow &window);
    void update(int speed);
    void createNewRow();
    int size();
    std::string getElementAt(int coor);
    void colorize(int s);
    void deColorize(int s);
    void erase(int s);
    Font getFont();
private:
    Font font;
    std::vector<Text> texts;
    std::string data[1000];
    int row;
    Clock clock,interwal;
};

