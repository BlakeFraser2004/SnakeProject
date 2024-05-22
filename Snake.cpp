#include "Snake.h"

// Constructor to initialize the snake with default settings
Snake::Snake(int gridSize) : gridSize(gridSize), speed(10.0f) {
    // Initial position and direction of the snake
    segments.push_back(sf::Vector2i(gridSize / 2, gridSize / 2));
    direction = sf::Vector2i(1, 0);
    // Snake color
    color = sf::Color::Green;
}

// Update function to move the snake
void Snake::update() {
    static sf::Clock clock; // Static clock to control snake movement speed

    // Check if enough time has passed for the snake to move
    if (clock.getElapsedTime().asSeconds() >= (1.0f / speed)) {
        sf::Vector2i newHead = segments.front() + direction; // Calculate new head position
        segments.insert(segments.begin(), newHead); // Insert new head
        segments.pop_back(); // Remove tail
        clock.restart(); // Restart the clock for next movement
    }
}

// Draw function to render the snake on the window
void Snake::draw(sf::RenderWindow& window) const {
    sf::RectangleShape segment(sf::Vector2f(gridSize - 1, gridSize - 1)); // Snake segment shape
    segment.setFillColor(color); // Set segment color

    // Draw each segment of the snake
    for (const auto& s : segments) {
         (void)window;
        segment.setPosition(static_cast<float>(s.x * gridSize), static_cast<float>(s.y * gridSize)); // Set segment position
        window.draw(segment); // Draw segment on window
    }
}

// Function to handle user input for controlling the snake
void Snake::handleInput(sf::RenderWindow&) {
    // Check for arrow key presses and update snake direction accordingly
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

// Function to grow the snake by adding a new segment
void Snake::grow() {
    sf::Vector2i lastSegmentPosition = segments.back(); // Get position of last segment
    segments.push_back(lastSegmentPosition); // Duplicate last segment
}

// Function to get the position of the snake's head
sf::Vector2i Snake::getHeadPosition() const {
    return segments.front(); // Return position of first segment (head)
}

// Function to get the size of the snake (number of segments)
int Snake::getSize() const {
    return segments.size(); // Return number of segments
}

// Function to check if the snake has collided with the game board border
bool Snake::checkCollisionWithBorder(const GameBoard& gameBoard) const {
    sf::Vector2i headPosition = segments.front(); // Get position of snake head
    // Check if head position is outside the game board
    if (headPosition.x < 0 || headPosition.x >= gameBoard.getBoardSize() || 
        headPosition.y < 0 || headPosition.y >= gameBoard.getBoardSize()) {
        return true; // Collision detected
    }
    return false; // No collision
}

// Function to reset the snake to its initial state
void Snake::reset() {
    segments.clear(); // Clear all segments
    segments.push_back(sf::Vector2i(gridSize / 2, gridSize / 2)); // Set initial position of snake
    direction = sf::Vector2i(1, 0); // Set initial direction (right)
}

// Function to get the position of the snake's head in window coordinates
sf::Vector2f Snake::getPosition() const {
    sf::Vector2i head = getHeadPosition(); // Get position of snake head
    return sf::Vector2f(static_cast<float>(head.x * gridSize), static_cast<float>(head.y * gridSize)); // Convert position to window coordinates
}
