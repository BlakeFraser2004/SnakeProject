#include "Snake.h"

Snake::Snake(int gridSize) : gridSize(gridSize), speed(15.00f) {
    segments.push_back(sf::Vector2i(15, 15)); // Initial position of the snake
    direction = sf::Vector2i(1, 0); // Initial direction (right)
    color = sf::Color::Green; // Snake color
}


void Snake::update() {
    // Adjust snake movement based on speed
    static sf::Clock clock; // Static clock to keep track of time

    // Check if enough time has elapsed based on the speed
    if (clock.getElapsedTime().asSeconds() >= (1.0f / speed)) {
        sf::Vector2i newHead = segments.front() + direction;
        segments.insert(segments.begin(), newHead);
        segments.pop_back();
        clock.restart(); // Restart the clock for the next movement
    }
}


// Other member functions...


void Snake::render(sf::RenderWindow& window) {
    sf::RectangleShape segment(sf::Vector2f(gridSize - 1, gridSize - 1));
    segment.setFillColor(color);

    for (size_t i = 0; i < segments.size(); ++i) {
        const sf::Vector2i& s = segments[i];
        segment.setPosition(s.x * gridSize, s.y * gridSize);
        window.draw(segment);
    }
}


void Snake::handleInput(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction = sf::Vector2i(0, -1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction = sf::Vector2i(0, 1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = sf::Vector2i(-1, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = sf::Vector2i(1, 0);
    }
}


void Snake::grow() {
    segments.push_back(segments.back());
}

sf::Vector2i Snake::getHeadPosition() {
    return segments.front();
}
