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



sf::Vector2i Snake::getHeadPosition() {
    return segments.front();
}

int Snake::getSize() const {
    return segments.size();
}


bool Snake::checkCollisionWithBorder(const GameBoard& gameBoard) {
    sf::Vector2i headPosition = segments.front();
    // Check if the head of the snake has collided with the borders
    if (headPosition.x < 0 || headPosition.x >= gameBoard.getBoardSize() || 
        headPosition.y < 0 || headPosition.y >= gameBoard.getBoardSize()) {
        return true; // Collision detected
    }
    return false; // No collision
}

bool Snake::checkSelfCollision(const sf::Vector2i& headPosition, const sf::Vector2i& foodPosition) {
    // Iterate through the segments of the snake's body, excluding the head
    for (size_t i = 1; i < segments.size(); ++i) {
        // Check if the head of the snake collides with any other segment, except the food position
        if (headPosition == segments[i] && headPosition != foodPosition) {
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

Snake::Snake(int gridSize) : GameObject(gridSize), gridSize(gridSize), direction(gridSize, 0) {
    shape.setFillColor(sf::Color::Green);
    body.push_back(shape);
}

void Snake::move() {
    for (std::size_t i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }
    body[0].move(direction);
}

void Snake::grow() {
    sf::RectangleShape newSegment(shape);
    newSegment.setPosition(body.back().getPosition());
    body.push_back(newSegment);
}

bool Snake::checkCollision() const {
    for (std::size_t i = 1; i < body.size(); ++i) {
        if (body[0].getGlobalBounds().intersects(body[i].getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : body) {
        window.draw(segment);
    }
}
