#pragma once

#include <iostream>
#include <string>
#include <vector>

template <class F, class S>
class group {
public:
    group(F, S);
    F first() const;
    S seconde() const;
private:
    F m_first;
    S m_seconde;
};

template <class F, class S>
group<F, S>::group(F first, S seconde) 
    : m_first(first), m_seconde(seconde)
{}

template <class F, class S>
F group<F, S>::first() const {
    return m_first; 
}

template <class F, class S>
S group<F, S>::seconde() const {
    return m_seconde; 
}

class decoder {
public:
    //m_code-i mijocov dzevavorvum e m_words-y, isk m_key-i mijocov dzevavorvum e m_word_keys-y
    decoder(std::string, std::string);
    //arden isk dzevavorvac m_code-i ev m_words-i mijocov karox enq stanal apakodavorvac 
    //tekst ev ayn pahel result-i mej vorpeszi amen angam anhrajeshturyun chlini apakodavorel nuyn bany
    std::string decoding();
    std::string coding();
private:
    std::string m_code;
    std::vector<std::string> m_words;
    std::string m_key;
    std::vector< std::vector< group<char, int> >  > m_word_keys;
    std::string m_result;
};





