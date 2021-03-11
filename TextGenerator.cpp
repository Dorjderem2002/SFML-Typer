//
//  TextGenerator.cpp
//  Typer++
//
//  Created by Dode Pep on 2/13/20.
//  Copyright © 2020 Dode. All rights reserved.
//

#include "TextGenerator.hpp"

TextGenerator::TextGenerator(int row) {
    srand(time(NULL));
    font.loadFromFile(resourcePath() + "Resources/Arial.ttf");
    this->row = row;
    std::ifstream reader(resourcePath() + "Resources/data.txt");
    int c = 0;
    while (getline(reader, data[c])) {
        c++;
    }
    reader.close();
    for(int i=0;i<row;i++) {
        Text tempText;
        tempText.setFont(font);
        tempText.setFillColor(Color::Green);
        tempText.setPosition(i * 800 / row, -(rand()%60 + 15));
        tempText.setCharacterSize(20);
        tempText.setString(data[rand()%999]);
        texts.push_back(tempText);
    }
}

void TextGenerator::draw(sf::RenderWindow &window) { 
    for(auto i : texts) {
        window.draw(i);
    }
}

void TextGenerator::update(int speed) {
    
    float del = clock.getElapsedTime().asSeconds();
    float gap = interwal.getElapsedTime().asSeconds();
    if(del > 1) {
        for(int i=0;i<texts.size();i++) {
            texts[i].setPosition(texts[i].getPosition() + Vector2f(0,speed));
        }
        clock.restart();
    }
    if(gap > 8.5) {
        for(int i=0;i<row;i++) {
            Text tempText;
            tempText.setFont(font);
            tempText.setFillColor(Color::Green);
            tempText.setPosition(i * 800 / row, -(rand()%60 + 15));
            tempText.setCharacterSize(20);
            tempText.setString(data[rand()%999]);
            texts.push_back(tempText);
        }
        interwal.restart();
    }
}

int TextGenerator::size() { 
    return texts.size();
}

std::string TextGenerator::getElementAt(int coor) {
    return texts[coor].getString();
}

void TextGenerator::colorize(int s) {
    texts[s].setFillColor(Color::Red);
}

void TextGenerator::deColorize(int s) {
    texts[s].setFillColor(Color::Green);
}

void TextGenerator::erase(int s) {
    texts.erase(texts.begin() + s);
}

sf::Font TextGenerator::getFont() { 
    return font;
}


