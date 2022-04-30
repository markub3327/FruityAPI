#ifndef VIEWER_HPP
#define VIEWER_HPP

#include "downloader.hpp"

using std::cout;

class Viewer {
    private:
        bool emoji;

    public:
        Viewer(bool emoji) : emoji(emoji) {}

        void show(const Downloader& dl) {
            auto response = dl.download();

            if (emoji)
            {
                if (response["name"] == "Apple") {
                    cout << "🍎🍎🍎" << std::endl;
                }
                else if (response["name"] == "Orange") {
                    cout << "🍊🍊🍊" << std::endl;
                }
            }

            cout << "Rod: " << response["genus"] << std::endl;
            cout << "Nazov: " << response["name"] << std::endl;
            cout << "Tuky: " << response["nutritions"]["fat"] << std::endl << std::endl;
        }
};

#endif