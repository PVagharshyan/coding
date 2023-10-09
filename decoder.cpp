#include "decoder.h"

#include <iostream>
#include <stdexcept>
#include <vector>

class utility {
    utility() = delete;
public: 
    static std::string rotate_str_l(std::string str) {
        char tmp = str[str.length() - 1];
        for (int i = str.length() - 1; i > 0; --i) {
            str[i] = str[i - 1];
        }
        str[0] = tmp;
        return str;
    }
    static std::string rotate_str_r(std::string str) {
        char tmp = str[0];
        for (int i {}; i < str.length() - 1; ++i) {
            str[i] = str[i + 1];
        }
        str[str.length() - 1] = tmp;
        return str;
    }
    static std::string left(std::string str) {
        if (str.length() != 8) {
            throw std::runtime_error("Error! str length out of range!");
        }
        int down[4] = {0, 1, 5, 4};
        std::string down_str = "";
        for (int i {}; i < 4; ++i) {
            down_str += str[down[i]];
        }
        down_str = rotate_str_l(down_str);
        int up[4] = {2, 3, 7, 6};
        std::string up_str = "";
        for (int i {}; i < 4; ++i) {
            up_str += str[up[i]];
        }
        up_str = rotate_str_l(up_str);
        for (int i {}; i < 4; ++i) {
            str[down[i]] = down_str[i];
        }
        for (int i {}; i < 4; ++i) {
            str[up[i]] = up_str[i];
        }
        return str;
    }
    static std::string right(std::string str) {
        if (str.length() != 8) {
            throw std::runtime_error("Error! str length out of range!");
        }
        int down[4] = {0, 1, 5, 4};
        std::string down_str = "";
        for (int i {}; i < 4; ++i) {
            down_str += str[down[i]];
        }
        down_str = rotate_str_r(down_str);
        int up[4] = {2, 3, 7, 6};
        std::string up_str = "";
        for (int i {}; i < 4; ++i) {
            up_str += str[up[i]];
        }
        up_str = rotate_str_r(up_str);
        for (int i {}; i < 4; ++i) {
            str[down[i]] = down_str[i];
        }
        for (int i {}; i < 4; ++i) {
            str[up[i]] = up_str[i];
        }
        return str;
    }
    static std::string up(std::string str) {
        if (str.length() != 8) {
            throw std::runtime_error("Error! str length out of range!");
        }
        int front[4] = {0, 1, 3, 2};
        std::string front_str = "";
        for (int i {}; i < 4; ++i) {
            front_str += str[front[i]];
        }
        front_str = rotate_str_l(front_str);
        int back[4] = {4, 5, 7, 6};
        std::string back_str = "";
        for (int i {}; i < 4; ++i) {
            back_str += str[back[i]];
        }
        back_str = rotate_str_l(back_str);
        for (int i {}; i < 4; ++i) {
            str[front[i]] = front_str[i];
        }
        for (int i {}; i < 4; ++i) {
            str[back[i]] = back_str[i];
        }
        return str;
    }
    static std::string down(std::string str) {
        if (str.length() != 8) {
            throw std::runtime_error("Error! str length out of range!");
        }
        int front[4] = {0, 1, 3, 2};
        std::string front_str = "";
        for (int i {}; i < 4; ++i) {
            front_str += str[front[i]];
        }
        front_str = rotate_str_r(front_str);
        int back[4] = {4, 5, 7, 6};
        std::string back_str = "";
        for (int i {}; i < 4; ++i) {
            back_str += str[back[i]];
        }
        back_str = rotate_str_r(back_str);
        for (int i {}; i < 4; ++i) {
            str[front[i]] = front_str[i];
        }
        for (int i {}; i < 4; ++i) {
            str[back[i]] = back_str[i];
        }
        return str;
    }
    static std::string rotate(std::string str, char direction, int count) { 
        switch (direction) {
            case 'u':
                for (int i {}; i < count; ++i) str = down(str);
                break;
            case 'd':
                for (int i {}; i < count; ++i) str = up(str);
                break;
            case 'l':
                for (int i {}; i < count; ++i) str = right(str);
                break;
            case 'r':
                for (int i {}; i < count; ++i) str = left(str);
                break;
        }
        return str;
    }
    static std::string rotate_c(std::string str, char direction, int count) { 
        switch (direction) {
            case 'u':
                for (int i {}; i < count; ++i) str = up(str);
                break;
            case 'd':
                for (int i {}; i < count; ++i) str = down(str);
                break;
            case 'l':
                for (int i {}; i < count; ++i) str = left(str);
                break;
            case 'r':
                for (int i {}; i < count; ++i) str = right(str);
                break;
        }
        return str;
    }
    static bool is_number(const std::string& str) {
        for (int i {}; i < str.length(); ++i) {
            if ((int)str[i] < (int)'0' || (int)str[i] > (int)'9') {
                return false;
            }
        }
        return true;
    }
    
    static int string_to_number(const std::string& str) {
        int result = 0;
        for (int i {}; i < str.length(); ++i) {
            result += (int)str[i] - (int)'0';
            result *= 10;
        }
        return result/10;
    }

    static bool check_key_word_element(const std::string& key_word) {
        std::string positions = "udlr";
        bool position_is_right = false;
        for (int i {}; i < positions.length(); ++i) {
            if (positions[i] == key_word[0]) {
                position_is_right = true;
            }
        }
        std::string count_rotations = "";
        for (int i { 1 }; i < key_word.length(); ++i) {
            count_rotations += key_word[i];
        }
        if (count_rotations == "") return false;
        bool rotate_count_is_right = is_number(count_rotations);
        return position_is_right && rotate_count_is_right;
    }
 
    static std::vector<std::string> split (const std::string& str, char c){
        std::string current = "";
        std::vector<std::string> result;
        for (int i = 0;i < str.length();++i){
            if (str[i] != c){
                current = current + std::string(1, str[i]);
            }
            else {
                if (current != "")
                    result.push_back(current);
                current = "";
            }
        }
        if (current != ""){
            result.push_back(current);
        }
        return result;
    }

    static bool check_key_word(const std::string& str) {      
        std::vector<std::string> v = split(str, ',');
        for (const auto& i : v) {
            if (!check_key_word_element(i)) {
                return false;
            }
        }
        return true;
    }
};

decoder::decoder(std::string code, std::string key) 
    : m_code(code), m_key(key), m_result("")
{
    int size = m_code.length()/8;
    for (int i {}; i < size; ++i) {    
        std::string result = "";
        for (int j {}; j < 8; ++j) {
            result += m_code[i*8 + j];
        }
        m_words.push_back(result);
    }
    if (m_code.length() % 8 != 0) {
        m_words.push_back("");
        for (int i { size*8 }; i < m_code.length(); ++i) {
            m_words[m_words.size() - 1] += m_code[i];
        }
        for (int i = m_words[m_words.size() - 1].length(); i < 8; ++i) {    
            m_words[m_words.size() - 1] += " ";
        }
    }
    std::vector<std::string> word_keys = utility::split(key, ':');
    for (const auto& j : word_keys) {
        if (!utility::check_key_word(j)) {
            throw std::runtime_error("Error! non valid key_word");
        }
        std::vector<std::string> v_current_key_word_elements = utility::split(j,',');
        std::vector<group<char, int>> current_key_word;
        for (const auto& k : v_current_key_word_elements) {
            std::string str = "";
            for (int p { 1 }; p < k.length(); ++p) {
                str += k[p];
            }
            
            int current_count_rotate = utility::string_to_number(str);
            current_key_word.push_back(group<char, int>(k[0], current_count_rotate));
        }

        m_word_keys.push_back(current_key_word);
    }
    if (m_words.size() != m_word_keys.size()) {
        throw std::runtime_error("Error: bolor \
                barery kodavorvac chen akm dranq gerazancum en berri\
                qanakin");
    }
}

std::string decoder::decoding() { 
    for (int i {}; i < m_words.size(); ++i) {
        std::string current_word = m_words[i];
        for (int j {}; j < m_word_keys[i].size(); ++j) {
            current_word = utility::rotate(current_word, m_word_keys[i][j].first(), m_word_keys[i][j].seconde()); 
        }
        m_result += current_word;
    }
    return m_result; 
}

std::string decoder::coding() { 
    for (int i {}; i < m_words.size(); ++i) {
        std::string current_word = m_words[i];
        for (int j {}; j < m_word_keys[i].size(); ++j) {
            current_word = utility::rotate_c(current_word, m_word_keys[i][j].first(), m_word_keys[i][j].seconde()); 
        }
        m_result += current_word;
    }
    return m_result; 
}
