#include "Snake.h"

Snake::Snake(int gridSize) : gridSize(gridSize), speed(10.00f) {
    segments.push_back(sf::Vector2i(gridSize / 2, gridSize / 2)); // Initial position of the snake
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

void Snake::draw(sf::RenderWindow& window) const {
    sf::RectangleShape segment(sf::Vector2f(gridSize - 1, gridSize - 1));
    segment.setFillColor(color);

    for (size_t i = 0; i < segments.size(); ++i) {
        const sf::Vector2i& s = segments[i];
        segment.setPosition(s.x * gridSize, s.y * gridSize);
        window.draw(segment);
    }
}

void Snake::handleInput(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != sf::Vector2i(0, 1)) {
        direction = sf::Vector2i(0, -1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != sf::Vector2i(0, -1)) {
        direction = sf::Vector2i(0, 1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != sf::Vector2i(1, 0)) {
        direction = sf::Vector2i(-1, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != sf::Vector2i(-1, 0)) {
        direction = sf::Vector2i(1, 0);
    }
}

void Snake::grow() {
    // Get the position of the last segment
    sf::Vector2i lastSegmentPosition = segments.back();
    
    // Duplicate the last segment
    segments.push_back(lastSegmentPosition);
    
    // Do not change direction here
}



sf::Vector2i Snake::getHeadPosition() const {
    return segments.front();
}

int Snake::getSize() const {
    return segments.size();
}


bool Snake::checkCollisionWithBorder(const GameBoard& gameBoard) const {
    sf::Vector2i headPosition = segments.front();
    // Check if the head of the snake has collided with the borders
    if (headPosition.x < 0 || headPosition.x >= gameBoard.getBoardSize() || 
        headPosition.y < 0 || headPosition.y >= gameBoard.getBoardSize()) {
        return true; // Collision detected
    }
    return false; // No collision
}

bool Snake::checkSelfCollision(const sf::Vector2i& headPosition) const {
    // Iterate through the segments of the snake's body, excluding the head
    for (size_t i = 1; i < segments.size(); ++i) {
        // Check if the head of the snake collides with any other segment, except the food position
        if (headPosition == segments[i]) {
            return true; // Collision detected
        }
    }
    return false; // No collision
}


void Snake::reset() {
    segments.clear(); // Clear all segments
    segments.push_back(sf::Vector2i(gridSize / 2, gridSize / 2)); // Initial position of the snake
    direction = sf::Vector2i(1, 0); // Initial direction (right)
}

sf::Vector2f Snake::getPosition() const {
    sf::Vector2i head = getHeadPosition();
    return sf::Vector2f(static_cast<float>(head.x * gridSize), static_cast<float>(head.y * gridSize));
}