#include <iostream>
// include related SFML libraries
#include <SFML/Graphics.hpp>

using namespace std;

// helper function
void setText(sf::Text &text, float x, float y){
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x/2.0f,
    textRect.position.y + textRect.size.y/2.0f));
    text.setPosition(sf::Vector2f(x, y));
}


void gameWindow() {
    unsigned int width = 900;
    unsigned int height = 600;
    auto window = sf::RenderWindow(sf::VideoMode({width, height}), "Prog2dew Valley", sf::Style::Close);

    sf::Font font("assets/fonts/MomoTrustDisplay.ttf");
    sf::Text game(font);
    game.setCharacterSize(40);
    game.setString("yay you're in the game!! \n we will develop next week");
    setText(game, width/2, height/2);
    game.setFillColor(sf::Color::Blue);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color(170, 202, 179));
        window.draw(game);
        window.display();
    }

}

// returns true or false depending if able to enter game or not
bool welcomeWindow() {
    unsigned int width = 900;
    unsigned int height = 600;

    // auto is VERY useful since typenames can get very long and annoying to deal with
    auto window = sf::RenderWindow(sf::VideoMode({width, height}), "Prog2dew Valley", sf::Style::Close);

    // TODO: display title font with the following specifications:
    // a. load MomoTrustDisplay located at assets/fonts/MomoTrustDisplay.ttf
    sf::Font title_font("assets/fonts/MomoTrustDisplay.ttf");

    // b. create text which uses font
    sf::Text title(title_font);
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    // use Vector2 is an SFML specific thing; allows us to store as {X Y} coordinates
    title.setString("ProgTwoah Valley");
    setText(title, width/2, height/2 - 130);

    // TODO: write button -> to play game

    // a. load font
    sf::Font button_font("assets/fonts/DotGothic16.ttf");
    // b. load text
    sf::Text play_button(button_font);
    play_button.setCharacterSize(32);
    play_button.setFillColor(sf::Color::White);
    play_button.setString("Play Game!");
    setText(play_button, width/2, height/2 + 20);

    // Get the text bounds
    sf::FloatRect textBounds = play_button.getLocalBounds();
    sf::RectangleShape play_button_rect({textBounds.size.x + 80, textBounds.size.y + 40});
    play_button_rect.setFillColor(sf::Color::Black);
    // moves origin of box from top-left to center; not really need to worry moreso aesthetics
    play_button_rect.setOrigin({play_button_rect.getSize().x / 2.f, play_button_rect.getSize().y / 2.f});
    // moves to wherever play button is!; also not neccessary for minesweeper
    play_button_rect.setPosition(play_button.getPosition());

    // TODO: write button -> to close game
    // a. load text
    sf::Text exit_button(button_font);
    exit_button.setCharacterSize(32);
    exit_button.setFillColor(sf::Color::White);
    exit_button.setString("Exit");
    setText(exit_button, width/2, height/2 + 120);

    // b. create button
    // lets preserve the size of the previous button
    sf::RectangleShape exit_button_rect({textBounds.size.x + 80, textBounds.size.y + 40});
    exit_button_rect.setFillColor(sf::Color::Black);
    // moves origin of box from top-left to center; not really need to worry moreso aesthetics
    exit_button_rect.setOrigin({exit_button_rect.getSize().x / 2.f, exit_button_rect.getSize().y / 2.f});
    // moves to wherever play button is!; also not neccessary for minesweeper
    exit_button_rect.setPosition(exit_button.getPosition());

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            // TODO: implement play button functionality (open a new screen)

            // TODO: implement exit button functionaltiy (closes)
            auto mousePos = sf::Mouse::getPosition(window); // get mouse position relative to window
            auto play_bound = play_button_rect.getGlobalBounds();
            auto exit_bound = exit_button_rect.getGlobalBounds();

            if (event->is<sf::Event::MouseButtonPressed>()) {
                cout << mousePos.x << " " << mousePos.y << endl;
                if (play_bound.position.x <= mousePos.x && mousePos.x <= play_bound.position.x + play_bound.size.x &&
                    play_bound.position.y <= mousePos.y && mousePos.y <= play_bound.position.y + play_bound.size.y) {
                    cout << "playing game!" << endl;
                    window.close();
                    return true;
                    }
                if (exit_bound.position.x <= mousePos.x && mousePos.x <= exit_bound.position.x + exit_bound.size.x &&
                    exit_bound.position.y <= mousePos.y && mousePos.y <= exit_bound.position.y + exit_bound.size.y) {
                    cout << "exit game!" << endl;
                    window.close();
                    return false;
                    }
            }
        }

        // TODO: set background
        window.clear(sf::Color::Blue);

        // TODO: draw elements
        window.draw(title);
        window.draw(play_button_rect);
        window.draw(play_button);
        window.draw(exit_button_rect);
        window.draw(exit_button);

        window.display();
    }
}

int main() {
    if (welcomeWindow())
        gameWindow();

    return 0;
}