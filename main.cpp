//
//  main.cpp
//  Typer++
//
//  Created by Dode Pep on 2/13/20.
//  Copyright © 2020 Dode. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "TextGenerator.hpp"
#include <string.h>
#include "ResourcePath.hpp"
using namespace sf;

bool matchFromFirst(std::string f,std::string s);

int main() {
    RenderWindow app(VideoMode(800,600),"Typer 2p");
    TextGenerator tgen(10);
    std::string currentText;
    Text text;
    Font font;
    font.loadFromFile(resourcePath() + "Resources/Arial.ttf");
    text.setPosition(0, 570);
    text.setCharacterSize(20);
    text.setFont(font);
    text.setFillColor(Color::Green);
    text.setString("text: ");
    app.setFramerateLimit(30);
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            switch (e.type) {
                case Event::Closed:
                    app.close();
                    break;
                case Event::TextEntered:
                    if(e.text.unicode == 8 && currentText.size() > 0) {
                        currentText.erase(currentText.size() - 1);
                    }
                    else if(e.text.unicode < 123 && e.text.unicode > 96) {
                        currentText += e.text.unicode;
                    }
                    for(int i=0;i<tgen.size();i++) {
                        if(tgen.getElementAt(i) == currentText) {
                            currentText = "";
                            tgen.erase(i);
                        }
                        else if(matchFromFirst(tgen.getElementAt(i),currentText)) {
                            tgen.colorize(i);
                        }
                        else {
                            tgen.deColorize(i);
                        }
                    }
                    text.setString("text: " + currentText);
                    break;
                default:
                    break;
            }
        }
        
        tgen.update(10);
        app.clear(Color::Black);
        tgen.draw(app);
        app.draw(text);
        app.display();
    }
    return 0;
}

bool matchFromFirst(std::string f,std::string s) {
    if(s.size() == 0) {
        return false;
    }
    for(int i=0;i<s.size();i++) {
        if(f[i] != s[i])
            return false;
    }
    return true;
}
