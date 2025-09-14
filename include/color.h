#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#define ESC "\033["
#define RESET "\033[m"

using namespace std;

// Format for future ref - "ESC[background_colour;Text_colourm output ESC[m"
// Link for medium article used for ref - https://medium.com/@vitorcosta.matias/print-coloured-texts-in-console-a0db6f589138

class COLOR {
private:
    string text_color;
    string background_color;
public:
    COLOR(string t_color, string bg_color) {
        text_color = t_color;
        background_color = bg_color;
    }
    void print_pretty_output(string text) {
        cout << ESC << background_color << ";" << text_color <<"m"<< text << RESET;
    }
    string get_pretty_text(string text) {
        string pretty_text = ESC + background_color + ";" + text_color + "m" + text + RESET;
        return pretty_text;
    }
};

#endif