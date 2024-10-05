//
// Created by Hà Tường Nguyên on 10/4/24.
//

#include "swan/color.h"

namespace nguyenpanda::swan {

    BaseColor::BaseColor(bool is_foreground)
            : is_foreground(is_foreground), seed(static_cast<int>(std::time(nullptr))), mt(seed), reset("\033[0m") {

    }

    BaseColor::BaseColor(int seed, bool is_foreground)
            : is_foreground(is_foreground), seed(seed), mt(seed), reset("\033[0m") {

    }

    std::string BaseColor::operator()(char color) const {
        return (*this)[std::to_string(color)];
    }

    std::string BaseColor::operator()(std::string color) const {
        return (*this)[std::move(color)];
    }

} // namespace nguyenpanda::swan

namespace nguyenpanda::swan {

    FourBitColor::FourBitColor(bool is_foreground, bool is_bright)
            : BaseColor(is_foreground), is_bright(is_bright) {
        ansi = is_bright ? (is_foreground ? "\033[1;9" : "\033[1;10")
                         : (is_foreground ? "\033[1;3" : "\033[1;4");
    }

    FourBitColor::FourBitColor(int seed, bool is_foreground, bool is_bright)
            : BaseColor(seed, is_foreground), is_bright(is_bright) {
        ansi = is_bright ? (is_foreground ? "\033[1;9" : "\033[1;10")
                         : (is_foreground ? "\033[1;3" : "\033[1;4");
    }

    std::string FourBitColor::operator[](char color) const {
        auto it = COLOR_KEYS.find(color);
        if (it != COLOR_KEYS.end()) {
            return ansi + it->second + 'm';
        } else {
            throw std::invalid_argument("Invalid color key.");
        }
    }

    std::string FourBitColor::operator[](std::string color) const {
        char c = static_cast<char>(std::tolower(color.front()));
        return (*this)[c];
    }

    std::string FourBitColor::random() const {
        std::uniform_int_distribution<int> dist(0, static_cast<int>(COLOR_KEYS.size()) - 1);
        auto it = COLOR_KEYS.begin();
        std::advance(it, dist(mt));
        return (*this)[it->first];
    }

    std::map<char, char> FourBitColor::COLOR_KEYS = {
            {' ', '0'},  // BLACK
            {'r', '1'},  // RED
            {'g', '2'},  // GREEN
            {'y', '3'},  // YELLOW
            {'b', '4'},  // BLUE
            {'m', '5'},  // MAGENTA
            {'c', '6'},  // CYAN
    };

} // namespace nguyenpanda::swan
